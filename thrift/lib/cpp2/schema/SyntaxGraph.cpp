/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/lib/cpp2/schema/SyntaxGraph.h>

#include <folly/lang/SafeAssert.h>
#include <thrift/lib/cpp/util/EnumUtils.h>
#include <thrift/lib/cpp2/dynamic/TypeSystem.h>
#include <thrift/lib/cpp2/schema/detail/Resolver.h>
#include <thrift/lib/cpp2/schema/detail/SchemaBackedResolver.h>

#include <fmt/core.h>

#include <queue>
#include <stdexcept>

#ifdef THRIFT_SCHEMA_AVAILABLE

namespace type = apache::thrift::type;
namespace protocol = apache::thrift::protocol;
using apache::thrift::util::enumNameSafe;

namespace apache::thrift::syntax_graph {

namespace detail {

const DefinitionNode& lookUpDefinition(
    const SyntaxGraph& syntaxGraph,
    const apache::thrift::type::DefinitionKey& definitionKey) {
  if (const DefinitionNode* def =
          syntaxGraph.resolver_->definitionOf(definitionKey)) {
    return *def;
  }
  folly::throw_exception<std::out_of_range>(
      fmt::format("Definition not found for key '{}'", definitionKey));
}

WithName::WithName(std::string_view name) : name_(name) {
  FOLLY_SAFE_DCHECK(
      name_.data()[name_.size()] == '\0',
      "name must be backed by a null-terminated string!");
}

} // namespace detail

TypeRef FieldNode::type() const {
  return *type_;
}

const protocol::Value* FOLLY_NULLABLE FieldNode::customDefault() const {
  if (customDefaultId_.has_value()) {
    return &resolver().valueOf(*customDefaultId_);
  }
  return nullptr;
}

const StructuredNode& FieldNode::parent() const {
  return detail::lazyResolve(resolver(), parent_).asStructured();
}

TypedefNode::TypedefNode(
    const detail::Resolver& resolver,
    const type::DefinitionKey& definitionKey,
    TypeRef&& targetType)
    : detail::WithDefinition(resolver, definitionKey),
      targetType_(folly::copy_to_unique_ptr(std::move(targetType))) {}

ConstantNode::ConstantNode(
    const detail::Resolver& resolver,
    const type::DefinitionKey& definitionKey,
    TypeRef&& type,
    type::ValueId valueId)
    : detail::WithDefinition(resolver, definitionKey),
      type_(folly::copy_to_unique_ptr(std::move(type))),
      valueId_(valueId) {}

const apache::thrift::protocol::Value& ConstantNode::value() const {
  return resolver().valueOf(valueId_);
}

List::List(TypeRef&& elementType)
    : elementType_(folly::copy_to_unique_ptr(std::move(elementType))) {}
List::List(const List& other)
    : elementType_(folly::copy_to_unique_ptr(other.elementType())) {}
List& List::operator=(const List& other) {
  elementType_ = folly::copy_to_unique_ptr(other.elementType());
  return *this;
}

bool operator==(const List& lhs, const List& rhs) {
  return lhs.elementType() == rhs.elementType();
}

/* static */ List List::of(TypeRef elementType) {
  return List(std::move(elementType));
}

Set::Set(TypeRef&& elementType)
    : elementType_(folly::copy_to_unique_ptr(std::move(elementType))) {}
Set::Set(const Set& other)
    : elementType_(folly::copy_to_unique_ptr(other.elementType())) {}
Set& Set::operator=(const Set& other) {
  elementType_ = folly::copy_to_unique_ptr(other.elementType());
  return *this;
}

bool operator==(const Set& lhs, const Set& rhs) {
  return lhs.elementType() == rhs.elementType();
}

/* static */ Set Set::of(TypeRef elementType) {
  return Set(std::move(elementType));
}

Map::Map(TypeRef&& keyType, TypeRef&& valueType)
    : keyType_(folly::copy_to_unique_ptr(std::move(keyType))),
      valueType_(folly::copy_to_unique_ptr(std::move(valueType))) {}
Map::Map(const Map& other)
    : keyType_(folly::copy_to_unique_ptr(other.keyType())),
      valueType_(folly::copy_to_unique_ptr(other.valueType())) {}
Map& Map::operator=(const Map& other) {
  keyType_ = folly::copy_to_unique_ptr(other.keyType());
  valueType_ = folly::copy_to_unique_ptr(other.valueType());
  return *this;
}

bool operator==(const Map& lhs, const Map& rhs) {
  return std::tie(lhs.keyType(), lhs.valueType()) ==
      std::tie(rhs.keyType(), rhs.valueType());
}

/* static */ Map Map::of(TypeRef keyType, TypeRef valueType) {
  return Map(std::move(keyType), std::move(valueType));
}

std::string_view toString(Primitive p) {
  switch (p) {
    case Primitive::BOOL:
      return "BOOL";
    case Primitive::BYTE:
      return "BYTE";
    case Primitive::I16:
      return "I16";
    case Primitive::I32:
      return "I32";
    case Primitive::I64:
      return "I64";
    case Primitive::FLOAT:
      return "FLOAT";
    case Primitive::DOUBLE:
      return "DOUBLE";
    case Primitive::STRING:
      return "STRING";
    case Primitive::BINARY:
      return "BINARY";
    default:
      folly::throw_exception<std::logic_error>(
          fmt::format("Unknown Primitive value '{}'", p));
  };
}

FunctionStream::FunctionStream(
    TypeRef&& payloadType, std::vector<FunctionNode::Exception>&& exceptions)
    : payloadType_(folly::copy_to_unique_ptr(std::move(payloadType))),
      exceptions_(std::move(exceptions)) {}

folly::span<const FunctionNode::Exception> FunctionStream::exceptions() const {
  return exceptions_;
}

FunctionSink::FunctionSink(
    TypeRef&& payloadType,
    TypeRef&& finalResponseType,
    std::vector<FunctionNode::Exception>&& clientExceptions,
    std::vector<FunctionNode::Exception>&& serverExceptions)
    : payloadType_(folly::copy_to_unique_ptr(std::move(payloadType))),
      finalResponseType_(
          folly::copy_to_unique_ptr(std::move(finalResponseType))),
      clientExceptions_(std::move(clientExceptions)),
      serverExceptions_(std::move(serverExceptions)) {}

folly::span<const FunctionNode::Exception> FunctionSink::clientExceptions()
    const {
  return clientExceptions_;
}

folly::span<const FunctionNode::Exception> FunctionSink::serverExceptions()
    const {
  return serverExceptions_;
}

TypeRef FunctionParam::type() const {
  return *type_;
}

TypeRef FunctionException::type() const {
  return *type_;
}

FunctionNode::FunctionNode(
    const detail::Resolver& resolver,
    const apache::thrift::type::DefinitionKey& parent,
    std::vector<Annotation>&& annotations,
    Response&& response,
    std::string_view name,
    std::vector<Param>&& params,
    std::vector<Exception>&& exceptions)
    : detail::WithResolver(resolver),
      detail::WithName(name),
      detail::WithAnnotations(std::move(annotations)),
      parent_(parent),
      response_(std::move(response)),
      params_(std::move(params)),
      exceptions_(std::move(exceptions)) {}

const RpcInterfaceNode& FunctionNode::parent() const {
  return detail::lazyResolve(resolver(), parent_).asRpcInterface();
}

folly::span<const FunctionNode::Exception> FunctionNode::exceptions() const {
  return exceptions_;
}

const ServiceNode* FOLLY_NULLABLE ServiceNode::baseService() const {
  return baseServiceKey_.has_value()
      ? &detail::lazyResolve(resolver(), *baseServiceKey_).asService()
      : nullptr;
}

DefinitionNode::DefinitionNode(
    const detail::Resolver& resolver,
    apache::thrift::type::ProgramId programId,
    std::vector<Annotation>&& annotations,
    std::string_view name,
    Alternative&& definition)
    : detail::WithResolver(resolver),
      detail::WithName(name),
      detail::WithAnnotations(std::move(annotations)),
      programId_(programId),
      definition_(std::move(definition)) {}

const ProgramNode& DefinitionNode::program() const {
  return resolver().programOf(programId_);
}

/* static */ TypeRef TypeRef::of(Primitive p) {
  return TypeRef(p);
}
/* static */ TypeRef TypeRef::of(const StructNode& s) {
  return TypeRef(detail::Lazy<StructNode>::Resolved(s));
}
/* static */ TypeRef TypeRef::of(const UnionNode& u) {
  return TypeRef(detail::Lazy<UnionNode>::Resolved(u));
}
/* static */ TypeRef TypeRef::of(const ExceptionNode& e) {
  return TypeRef(detail::Lazy<ExceptionNode>::Resolved(e));
}
/* static */ TypeRef TypeRef::of(const EnumNode& e) {
  return TypeRef(detail::Lazy<EnumNode>::Resolved(e));
}
/* static */ TypeRef TypeRef::of(const List& list) {
  return TypeRef(list);
}
/* static */ TypeRef TypeRef::of(const Set& set) {
  return TypeRef(set);
}
/* static */ TypeRef TypeRef::of(const Map& map) {
  return TypeRef(map);
}

bool operator==(const TypeRef& lhs, const TypeRef& rhs) {
  if (lhs.kind() != rhs.kind()) {
    return false;
  }
  return lhs.visit(
      [&](Primitive p) -> bool { return rhs.asPrimitive() == p; },
      [&](const StructNode& s) -> bool { return &rhs.asStruct() == &s; },
      [&](const UnionNode& u) -> bool { return &rhs.asUnion() == &u; },
      [&](const ExceptionNode& e) -> bool { return &rhs.asException() == &e; },
      [&](const EnumNode& e) -> bool { return &rhs.asEnum() == &e; },
      [&](const TypedefNode& t) -> bool { return &rhs.asTypedef() == &t; },
      [&](const List& l) -> bool { return rhs.asList() == l; },
      [&](const Set& s) -> bool { return rhs.asSet() == s; },
      [&](const Map& m) -> bool { return rhs.asMap() == m; });
}

bool operator==(const TypeRef& lhs, const DefinitionNode& rhs) {
  return lhs.visit(
      [&](const StructNode& s) -> bool {
        return rhs.isStruct() && &rhs.asStruct() == &s;
      },
      [&](const UnionNode& u) -> bool {
        return rhs.isUnion() && &rhs.asUnion() == &u;
      },
      [&](const ExceptionNode& e) -> bool {
        return rhs.isException() && &rhs.asException() == &e;
      },
      [&](const EnumNode& e) -> bool {
        return rhs.isEnum() && &rhs.asEnum() == &e;
      },
      [&](const TypedefNode& t) -> bool {
        return rhs.isTypedef() && &rhs.asTypedef() == &t;
      },
      [&](auto&&) -> bool {
        // All other forms are non-type definitions.
        return false;
      });
}

Annotation::Annotation(
    TypeRef&& type,
    const std::map<std::string, apache::thrift::protocol::Value>& fields)
    : type_(folly::copy_to_unique_ptr(std::move(type))) {
  value_ = folly::dynamic::object();
  for (const auto& [n, v] : fields) {
    value_[n] = v.toDynamicImpl();
  }
}

ProgramNode::IncludesList ProgramNode::includes() const {
  IncludesList includes;
  for (const type::ProgramId& include : includes_) {
    includes.emplace_back(&resolver().programOf(include));
  }
  return includes;
}

ProgramNode::DefinitionsByName ProgramNode::definitionsByName() const {
  DefinitionsByName result;
  for (folly::not_null<const DefinitionNode*> definition : definitions_) {
    result.emplace(definition->name(), definition);
  }
  return result;
}

/* static */ SyntaxGraph SyntaxGraph::fromSchema(
    folly::not_null<const type::Schema*> schema) {
  return SyntaxGraph{detail::createResolverfromSchemaRef(*schema)};
}

/* static */ SyntaxGraph SyntaxGraph::fromSchema(type::Schema&& schema) {
  return SyntaxGraph{detail::createResolverfromSchema(std::move(schema))};
}

SyntaxGraph::SyntaxGraph(std::unique_ptr<detail::Resolver> resolver)
    : resolver_(std::move(resolver)) {}

SyntaxGraph::SyntaxGraph(SyntaxGraph&&) noexcept = default;
SyntaxGraph& SyntaxGraph::operator=(SyntaxGraph&&) noexcept = default;
SyntaxGraph::~SyntaxGraph() noexcept = default;

ProgramNode::IncludesList SyntaxGraph::programs() const {
  return resolver_->programs();
}

namespace detail {

WithAnnotations::WithAnnotations(std::vector<Annotation>&& annotations)
    : annotations_(std::move(annotations)) {}

folly::span<const Annotation> WithAnnotations::annotations() const {
  return annotations_;
}

const DefinitionNode& lazyResolve(
    const Resolver& resolver, const type::DefinitionKey& definitionKey) {
  if (const auto* definition = resolver.definitionOf(definitionKey)) {
    return *definition;
  }
  folly::throw_exception<InvalidSyntaxGraphError>(
      fmt::format("Definition key {} not found", definitionKey));
}

} // namespace detail

void FieldNode::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print(
      "FieldNode (id={}, presence={}, name='{}')",
      id(),
      enumNameSafe(presence()),
      name());
  type().printTo(scope.make_child("type = "), visited);
  if (customDefault()) {
    // TODO(praihan): Implement printing custom default values
    scope.make_child("customDefault = ...");
  }
}

void StructNode::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("StructNode '{}'", definition().name());
  if (visited.mark(definition()).already) {
    return;
  }
  for (const auto& field : fields()) {
    field.printTo(scope.make_child(), visited);
  }
}

void UnionNode::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("UnionNode '{}'", definition().name());
  if (visited.mark(definition()).already) {
    return;
  }
  for (const auto& field : fields()) {
    field.printTo(scope.make_child(), visited);
  }
}

void ExceptionNode::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("ExceptionNode '{}'", definition().name());
  if (visited.mark(definition()).already) {
    return;
  }
  for (const auto& field : fields()) {
    field.printTo(scope.make_child(), visited);
  }
}

void EnumNode::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("EnumNode '{}'", definition().name());
  if (visited.mark(definition()).already) {
    return;
  }
  for (const auto& entry : values()) {
    scope.make_child("'{}' → {}", entry.name(), entry.i32());
  }
}

void TypedefNode::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("TypedefNode '{}'", definition().name());
  if (visited.mark(definition()).already) {
    return;
  }
  targetType().printTo(scope.make_child("targetType = "), visited);
}

void ConstantNode::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("ConstantNode '{}'", definition().name());
  if (visited.mark(definition()).already) {
    return;
  }
  type().printTo(scope.make_child("type = "), visited);
  // TODO(praihan): Implement printing constant values
  scope.make_child("value = ...");
}

void List::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("List");
  elementType().printTo(scope.make_child("elementType = "), visited);
}

void Set::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("Set");
  elementType().printTo(scope.make_child("elementType = "), visited);
}

void Map::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("Map");
  keyType().printTo(scope.make_child("keyType = "), visited);
  valueType().printTo(scope.make_child("valueType = "), visited);
}

void TypeRef::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  visit(
      [&](const Primitive& primitive) {
        scope.print("{}", enumNameSafe(primitive));
      },
      [&](const auto& node) { node.printTo(scope, visited); });
}

void FunctionNode::Stream::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("FunctionNode::Stream");

  // A Thrift stream in IDL takes the form:
  //     stream<{payloadType} throws (... {exceptions} ...)>

  payloadType().printTo(scope.make_child("payloadType = "), visited);
  if (folly::span<const FunctionNode::Exception> excepts = exceptions();
      !excepts.empty()) {
    tree_printer::scope& exceptionsScope = scope.make_child("exceptions");
    for (const FunctionNode::Exception& e : excepts) {
      e.printTo(exceptionsScope.make_child(), visited);
    }
  }
}

void FunctionNode::Sink::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("FunctionNode::Sink");

  // A Thrift sink in IDL takes the form:
  //     sink<{payloadType} throws (... {clientExceptions} ...),
  //          {finalResponseType} throws (... {serverExceptions} ...)>

  payloadType().printTo(scope.make_child("payloadType = "), visited);
  if (folly::span<const FunctionNode::Exception> exceptions =
          clientExceptions();
      !exceptions.empty()) {
    tree_printer::scope& clientExceptionsScope =
        scope.make_child("clientExceptions");
    for (const FunctionNode::Exception& e : exceptions) {
      e.printTo(clientExceptionsScope.make_child(), visited);
    }
  }

  finalResponseType().printTo(
      scope.make_child("finalResponseType = "), visited);
  if (folly::span<const FunctionNode::Exception> exceptions =
          serverExceptions();
      !exceptions.empty()) {
    tree_printer::scope& serverExceptionsScope =
        scope.make_child("serverExceptions");
    for (const FunctionNode::Exception& e : exceptions) {
      e.printTo(serverExceptionsScope.make_child(), visited);
    }
  }
}

void FunctionNode::Response::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("FunctionNode::Response");

  tree_printer::scope& returnTypeNode = scope.make_child("returnType = ");
  if (const TypeRef* ret = type()) {
    ret->printTo(returnTypeNode, visited);
  } else {
    returnTypeNode.print("void");
  }
  if (const InteractionNode* returnedInteraction = interaction()) {
    returnedInteraction->printTo(scope.make_child(), visited);
  }

  if (const FunctionNode::Sink* sinkNode = sink()) {
    sinkNode->printTo(scope.make_child(), visited);
  } else if (const FunctionNode::Stream* streamNode = stream()) {
    streamNode->printTo(scope.make_child(), visited);
  }
}

void FunctionNode::Param::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("FunctionNode::Param (id={}, name='{}')", id(), name());
  type().printTo(scope.make_child("type = "), visited);
}

void FunctionNode::Exception::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("FunctionNode::Exception (id={}, name='{}')", id(), name());
  type().printTo(scope.make_child("type = "), visited);
}

void FunctionNode::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("FunctionNode (name='{}')", name());
  response().printTo(scope.make_child(), visited);

  if (folly::span<const FunctionNode::Param> paramList = params();
      !paramList.empty()) {
    tree_printer::scope& paramsScope = scope.make_child("params");
    for (const FunctionNode::Param& p : paramList) {
      p.printTo(paramsScope.make_child(), visited);
    }
  }

  if (folly::span<const FunctionNode::Exception> exceptionsList = exceptions();
      !exceptionsList.empty()) {
    tree_printer::scope& exceptionsScope = scope.make_child("exceptions");
    for (const FunctionNode::Exception& e : exceptionsList) {
      e.printTo(exceptionsScope.make_child(), visited);
    }
  }
}

void ServiceNode::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("ServiceNode (name='{}')", definition().name());
  if (visited.mark(definition()).already) {
    return;
  }

  if (const ServiceNode* base = baseService()) {
    base->printTo(scope.make_child("baseService = "), visited);
  }

  if (folly::span<const FunctionNode> funcs = functions(); !funcs.empty()) {
    tree_printer::scope& functionsScope = scope.make_child("functions");
    for (const FunctionNode& f : funcs) {
      f.printTo(functionsScope.make_child(), visited);
    }
  }
}

void InteractionNode::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("InteractionNode (name='{}')", definition().name());
  if (visited.mark(definition()).already) {
    return;
  }

  if (folly::span<const FunctionNode> funcs = functions(); !funcs.empty()) {
    tree_printer::scope& functionsScope = scope.make_child("functions");
    for (const FunctionNode& f : funcs) {
      f.printTo(functionsScope.make_child(), visited);
    }
  }
}

void DefinitionNode::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("DefinitionNode (name='{}')", name());
  if (visited.mark(*this).already) {
    return;
  }
  visit([&](const auto& def) { def.printTo(scope.make_child(), visited); });
}

void Annotation::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("Annotation");
  type().printTo(scope.make_child("type = "), visited);
  // TODO(praihan): Implement printing annotation values
  scope.make_child("value = ...");
}

void ProgramNode::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("ProgramNode (path='{}')", path());
  if (visited.mark(*this).already) {
    return;
  }

  if (ProgramNode::IncludesList includesList = includes();
      !includesList.empty()) {
    tree_printer::scope& includesScope = scope.make_child("includes");
    for (folly::not_null<const ProgramNode*> include : includesList) {
      include->printTo(includesScope.make_child(), visited);
    }
  }

  if (ProgramNode::Definitions definitionsList = definitions();
      !definitionsList.empty()) {
    tree_printer::scope& definitionsScope = scope.make_child("definitions");
    for (folly::not_null<const DefinitionNode*> def : definitionsList) {
      def->printTo(definitionsScope.make_child(), visited);
    }
  }
}

void SyntaxGraph::printTo(
    tree_printer::scope& scope, detail::VisitationTracker& visited) const {
  scope.print("SyntaxGraph");
  tree_printer::scope& programsScope = scope.make_child("programs");
  for (folly::not_null<const ProgramNode*> program : programs()) {
    program->printTo(programsScope.make_child(), visited);
  }
}

namespace {
class TypeSystemFacade final : public type_system::TypeSystem {
  // Thrift files (and therefore SyntaxGraph) cannot define opaque alias types.
  // Therefore, they are not necessary for the TypeSystem for SyntaxGraph.
  using TSDefinition = std::variant<
      type_system::StructNode,
      type_system::UnionNode,
      type_system::EnumNode>;

 public:
  explicit TypeSystemFacade(const detail::SchemaBackedResolver& graph)
      : resolver_(graph) {}

  std::optional<type_system::DefinitionRef> getUserDefinedType(
      type_system::UriView uri) const override {
    if (const DefinitionNode* def = resolver_.getDefinitionNodeByUri(uri)) {
      return convertUserDefinedType(def);
    }
    return std::nullopt;
  }

  std::optional<folly::F14FastSet<type_system::Uri>> getKnownUris()
      const override {
    // This is only used for serializing the type system, which is already not
    // guaranteed to be possible as we don't require URIs for all user-defined
    // types.
    return std::nullopt;
  }

  // Convert the definition to TypeSystem's representation.
  type_system::DefinitionRef convertUserDefinedType(
      const DefinitionNode* def) const {
    auto toTSDefinitionRef = [](const TSDefinition* ts) {
      return folly::variant_match(*ts, [](auto& member) {
        return type_system::DefinitionRef{&member};
      });
    };

    {
      std::shared_lock rlock(cacheMutex_);
      if (auto cached = folly::get_ptr(cache_, def)) {
        return toTSDefinitionRef(cached);
      }
    }

    std::unique_lock wlock(cacheMutex_);
    if (auto cached = folly::get_ptr(cache_, def)) {
      return toTSDefinitionRef(cached);
    }

    // Holding the lock allows shedding the const qualifier
    return const_cast<TypeSystemFacade&>(*this).convertUserDefinedType(def);
  }

  const DefinitionNode& reverseUserDefinedType(
      const type_system::DefinitionNode& node) const {
    std::shared_lock rlock(cacheMutex_);
    if (auto it = reverseCache_.find(&node); it != reverseCache_.end()) {
      return *it->second;
    }
    folly::throw_exception<std::runtime_error>(
        "Could not find the original SyntaxGraph Definition node for the given type.");
  }

 private:
  // Convert the definition to TypeSystem's representation.
  // Caller must hold the write lock.
  // The approach is:
  // 1. Traverse the root definition node's fields to gather the set of
  // definitions that need to be converted (as a structured definition node has
  // pointers to its fields' types). This is done using BFS to avoid unbounded
  // user-controlled recursion.
  // 2. Allocate a placeholder object for each structured definition in the set,
  // so that even in cases of circular references we still have a stable address
  // for the type of each field available during population. (Enum definitions
  // are populated immediately as they don't have outgoing edges). This
  // is done during the traversal in the first step.
  // 3. Populate the placeholder objects with the actual data.
  type_system::DefinitionRef convertUserDefinedType(
      const DefinitionNode* rootSgDef) {
    // This is the queue for the first traversal, performing steps 1 and 2.
    std::queue<const DefinitionNode*> initialAllocationQueue;
    initialAllocationQueue.push(rootSgDef);
    // This is the queue for the second traversal, performing step 3.
    // Nodes are added to it as they are processed by the first traversal.
    std::queue<const DefinitionNode*> populationQueue;
    while (!initialAllocationQueue.empty()) {
      const DefinitionNode* sgDef = initialAllocationQueue.front();
      initialAllocationQueue.pop();
      if (cache_.contains(sgDef)) {
        continue;
      }

      auto processStructuredType = [&](const StructuredNode& s) {
        std::function<void(const TypeRef&)> visitType = [&](const TypeRef& t) {
          auto enqueue = [&](const DefinitionNode& def) {
            if (!cache_.contains(&def)) {
              initialAllocationQueue.push(&def);
            }
          };
          t.trueType().visit(
              [&](const StructuredNode& n) { enqueue(n.definition()); },
              [&](const EnumNode& n) { enqueue(n.definition()); },
              [&](const TypedefNode& n) { enqueue(n.definition()); },
              [&](const List& l) { visitType(l.elementType()); },
              [&](const Set& l) { visitType(l.elementType()); },
              [&](const Map& m) {
                visitType(m.keyType());
                visitType(m.valueType());
              },
              [](const Primitive&) {});
        };

        for (const auto& field : s.fields()) {
          visitType(field.type());
        }

        // Enqueue the current node to be populated later.
        populationQueue.push(sgDef);
      };

      // We may encounter circular references, so we insert a placeholder object
      // into the map that we will later overwrite with the correct data.
      sgDef->visit(
          [&](const StructNode& s) {
            auto [entry, _] =
                cache_.emplace(sgDef, type_system::StructNode{{}, {}, {}, {}});
            reverseCache_.emplace(
                &std::get<type_system::StructNode>(entry->second), sgDef);
            processStructuredType(s);
          },
          [&](const UnionNode& s) {
            auto [entry, _] =
                cache_.emplace(sgDef, type_system::UnionNode{{}, {}, {}, {}});
            reverseCache_.emplace(
                &std::get<type_system::UnionNode>(entry->second), sgDef);
            processStructuredType(s);
          },
          [](const ExceptionNode&) {
            folly::throw_exception<std::runtime_error>(
                "Exceptions aren't supported by TypeSystem");
          },
          [&](const EnumNode& e) {
            // Enums can be populated immediately.
            std::vector<type_system::EnumNode::Value> values;
            values.reserve(e.values().size());
            for (const auto& value : e.values()) {
              // TODO: annotations
              values.emplace_back(type_system::EnumNode::Value{
                  std::string(value.name()),
                  value.i32(),
                  type_system::AnnotationsMap{}});
            }
            // TODO: annotations
            auto [entry, _] = cache_.emplace(
                sgDef,
                type_system::EnumNode{
                    type_system::Uri(e.uri()), std::move(values), {}});
            reverseCache_.emplace(
                &std::get<type_system::EnumNode>(entry->second), sgDef);
          },
          [](const TypedefNode&) {
            folly::throw_exception<std::logic_error>(
                "Typedefs should have been resolved by trueType call");
          },
          [](const auto& n) {
            folly::throw_exception<std::logic_error>(fmt::format(
                "Encountered unexpected node type `{}`",
                folly::pretty_name<decltype(n)>()));
          });
    }

    // Now that all types have been allocated, go back and populate structured
    // types.
    while (!populationQueue.empty()) {
      const DefinitionNode* sgDef = populationQueue.front();
      populationQueue.pop();
      TSDefinition& tsDef = cache_.at(sgDef);
      auto makeFields = [&](const auto& s) {
        bool isUnion = std::is_same_v<decltype(s), UnionNode const&>;
        std::vector<type_system::FieldNode> fields;
        fields.reserve(s.fields().size());
        for (const auto& field : s.fields()) {
          fields.emplace_back(
              type_system::FieldIdentity{field.id(), std::string(field.name())},
              // TODO: SyntaxGraph doesn't ever set this to terse but TypeSystem
              // does.
              isUnion ? type_system::PresenceQualifier::OPTIONAL_
                      : static_cast<type_system::PresenceQualifier>(
                            field.presence()),
              convertType(field.type()),
              // TODO: default value
              std::nullopt,
              // TODO: annotations
              type_system::AnnotationsMap{}

          );
        }
        return fields;
      };
      sgDef->visit(
          [&](const StructNode& s) {
            std::get<type_system::StructNode>(tsDef) = type_system::StructNode{
                type_system::Uri(s.uri()),
                makeFields(s),
                false,
                type_system::AnnotationsMap{}};
          },
          [&](const UnionNode& s) {
            std::get<type_system::UnionNode>(tsDef) = type_system::UnionNode{
                type_system::Uri(s.uri()),
                makeFields(s),
                false,
                type_system::AnnotationsMap{}};
          },
          [](const auto& n) {
            folly::throw_exception<std::logic_error>(fmt::format(
                "Encountered unexpected node type `{}`",
                folly::pretty_name<decltype(n)>()));
          });
    }

    return folly::variant_match(cache_.at(rootSgDef), [](auto& def) {
      return type_system::DefinitionRef{&def};
    });
  }

  type_system::TypeRef convertType(const TypeRef& type) {
    return type.trueType().visit(
        [](const Primitive& primitive) {
          switch (primitive) {
            case Primitive::BOOL:
              return type_system::TypeSystem::Bool();
            case Primitive::BYTE:
              return type_system::TypeSystem::Byte();
            case Primitive::I16:
              return type_system::TypeSystem::I16();
            case Primitive::I32:
              return type_system::TypeSystem::I32();
            case Primitive::I64:
              return type_system::TypeSystem::I64();
            case Primitive::FLOAT:
              return type_system::TypeSystem::Float();
            case Primitive::DOUBLE:
              return type_system::TypeSystem::Double();
            case Primitive::STRING:
              return type_system::TypeSystem::String();
            case Primitive::BINARY:
              return type_system::TypeSystem::Binary();
          }
        },
        [&](const StructNode& s) {
          return type_system::TypeRef{
              std::get<type_system::StructNode>(cache_.at(&s.definition()))};
        },
        [&](const UnionNode& u) {
          return type_system::TypeRef{
              std::get<type_system::UnionNode>(cache_.at(&u.definition()))};
        },
        [&](const ExceptionNode&) -> type_system::TypeRef {
          folly::throw_exception<std::runtime_error>(
              "Exceptions aren't supported by TypeSystem");
        },
        [&](const EnumNode& e) {
          return type_system::TypeRef{
              std::get<type_system::EnumNode>(cache_.at(&e.definition()))};
        },
        [&](const TypedefNode&) -> type_system::TypeRef {
          folly::throw_exception<std::logic_error>(
              "Typedefs should have been resolved by trueType call");
        },
        [&](const List& l) {
          return type_system::TypeSystem::ListOf(convertType(l.elementType()));
        },
        [&](const Set& s) {
          return type_system::TypeSystem::SetOf(convertType(s.elementType()));
        },
        [&](const Map& m) {
          return type_system::TypeSystem::MapOf(
              convertType(m.keyType()), convertType(m.valueType()));
        });
  }

  const detail::SchemaBackedResolver& resolver_;
  folly::F14NodeMap<const DefinitionNode*, TSDefinition> cache_;
  folly::F14NodeMap<const type_system::DefinitionNode*, const DefinitionNode*>
      reverseCache_;
  mutable folly::SharedMutex cacheMutex_;
};
} // namespace

const type_system::TypeSystem& SyntaxGraph::asTypeSystem() const {
  if (auto facade = typeSystemFacade_.rlock(); *facade) {
    return **facade;
  }
  if (auto* resolver = dynamic_cast<const detail::SchemaBackedResolver*>(
          resolver_.get().unwrap())) {
    auto facade = typeSystemFacade_.wlock();
    if (!*facade) {
      *facade = std::make_unique<TypeSystemFacade>(*resolver);
    }
    return **facade;
  }
  folly::throw_exception<std::runtime_error>(
      "SyntaxGraph instance does not support URI-based lookup");
}

type_system::DefinitionRef SyntaxGraph::asTypeSystemDefinitionRef(
    const DefinitionNode& node) const {
  auto& facade = static_cast<const TypeSystemFacade&>(asTypeSystem());
  return facade.convertUserDefinedType(&node);
}
const type_system::StructNode& SyntaxGraph::asTypeSystemStructNode(
    const StructNode& node) const {
  return asTypeSystemDefinitionRef(node.definition()).asStruct();
}
const type_system::UnionNode& SyntaxGraph::asTypeSystemUnionNode(
    const UnionNode& node) const {
  return asTypeSystemDefinitionRef(node.definition()).asUnion();
}
const type_system::EnumNode& SyntaxGraph::asTypeSystemEnumNode(
    const EnumNode& node) const {
  return asTypeSystemDefinitionRef(node.definition()).asEnum();
}

const DefinitionNode& SyntaxGraph::asSyntaxGraphDefinition(
    const type_system::DefinitionNode& node) const {
  auto& facade = static_cast<const TypeSystemFacade&>(asTypeSystem());
  return facade.reverseUserDefinedType(node);
}
const StructNode& SyntaxGraph::asSyntaxGraphStructNode(
    const type_system::StructNode& node) const {
  return asSyntaxGraphDefinition(node).asStruct();
}
const UnionNode& SyntaxGraph::asSyntaxGraphUnionNode(
    const type_system::UnionNode& node) const {
  return asSyntaxGraphDefinition(node).asUnion();
}
const EnumNode& SyntaxGraph::asSyntaxGraphEnumNode(
    const type_system::EnumNode& node) const {
  return asSyntaxGraphDefinition(node).asEnum();
}

} // namespace apache::thrift::syntax_graph

#endif // THRIFT_SCHEMA_AVAILABLE
