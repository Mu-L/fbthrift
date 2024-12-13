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

#include <folly/portability/GMock.h>
#include <folly/portability/GTest.h>

#include <thrift/compiler/whisker/diagnostic.h>
#include <thrift/compiler/whisker/object.h>
#include <thrift/compiler/whisker/test/render_test_helpers.h>

namespace w = whisker::make;

namespace whisker {

namespace {
class empty_native_object : public native_object {};
} // namespace

TEST_F(RenderTest, basic) {
  auto result = render(
      "Some text {{foo}} More text", w::map({{"foo", w::string("bar")}}));
  EXPECT_EQ(*result, "Some text bar More text");
}

TEST_F(RenderTest, variable_missing_in_scope) {
  auto result = render("Some text {{foo}} More text", w::map({}));
  EXPECT_FALSE(result.has_value());
  EXPECT_THAT(
      diagnostics(),
      testing::ElementsAre(diagnostic(
          diagnostic_level::error,
          "Name 'foo' was not found in the current scope. Tried to search through the following scopes:\n"
          "#0 map (size=0)\n"
          "\n"
          "#1 <global scope> (size=0)\n",
          path_to_file,
          1)));
}

TEST_F(RenderTest, variable_missing_property_in_object) {
  auto result = render(
      "Some text {{foo.bar}} More text",
      w::map({{"foo", w::map({{"baz", w::string("qux")}})}}));
  EXPECT_FALSE(result.has_value());
  EXPECT_THAT(
      diagnostics(),
      testing::ElementsAre(diagnostic(
          diagnostic_level::error,
          "Object 'foo' has no property named 'bar'. The object with the missing property is:\n"
          "map (size=1)\n"
          "`-'baz'\n"
          "  |-'qux'\n",
          path_to_file,
          1)));
}

TEST_F(RenderTest, section_block_array) {
  auto result = render(
      "The factorial function looks like:{{#factorials}}\n"
      "{{.}}{{/factorials}}",
      w::map(
          {{"factorials",
            w::array(
                {w::i64(1), w::i64(2), w::i64(6), w::i64(24), w::i64(120)})}}));
  EXPECT_EQ(
      *result,
      "The factorial function looks like:\n"
      "1\n"
      "2\n"
      "6\n"
      "24\n"
      "120");
}

TEST_F(RenderTest, section_block_array_nested) {
  auto result = render(
      "{{#.}}{{#b}} {{c}} {{/b}}{{/.}}",
      w::array(
          {w::map(
               {{"b",
                 w::array(
                     {w::map({{"c", w::i64(1)}}),
                      w::map({{"c", w::i64(2)}})})}}),
           w::map(
               {{"b",
                 w::array(
                     {w::map({{"c", w::i64(3)}}),
                      w::map({{"c", w::i64(4)}})})}}),
           w::map(
               {{"b",
                 w::array(
                     {w::map({{"c", w::i64(5)}}),
                      w::map({{"c", w::i64(6)}})})}})}));
  EXPECT_EQ(*result, " 1  2  3  4  5  6 ");
}

TEST_F(RenderTest, section_block_array_with_nested_objects) {
  auto result = render(
      "The factorial function looks like:\n"
      "{{#factorials}}\n"
      "  {{value}}\n"
      "{{/factorials}}",
      w::map(
          {{"factorials",
            w::array(
                {w::map({{"value", w::i64(1)}}),
                 w::map({{"value", w::string("2")}}),
                 w::map({{"value", w::i64(6)}}),
                 w::map({{"value", w::i64(24)}}),
                 w::map({{"value", w::i64(120)}})})}}));
  EXPECT_EQ(
      *result,
      "The factorial function looks like:\n"
      "  1\n"
      "  2\n"
      "  6\n"
      "  24\n"
      "  120\n");
}

TEST_F(RenderTest, section_block_array_asymmetric_nested_scopes) {
  auto result = render(
      "The factorial function looks like:\n"
      "{{#factorials}}\n"
      "  {{value}}\n"
      "{{/factorials}}",
      w::map(
          {{"factorials",
            w::array(
                {w::map({{"value", w::i64(1)}}),
                 w::map({{"oops", w::null}}), // missing value, scoped should
                                              // have been cleared
                 w::map({{"value", w::i64(6)}}),
                 w::map({{"value", w::i64(24)}}),
                 w::map({{"value", w::i64(120)}})})}}));
  EXPECT_THAT(
      diagnostics(),
      testing::ElementsAre(diagnostic(
          diagnostic_level::error,
          "Name 'value' was not found in the current scope. Tried to search through the following scopes:\n"
          "#0 map (size=1)\n"
          "`-'oops'\n"
          "  |-null\n"
          "\n"
          "#1 map (size=1)\n"
          "`-'factorials'\n"
          "  |-...\n"
          "\n"
          "#2 <global scope> (size=0)\n",
          path_to_file,
          3)));
}

TEST_F(RenderTest, section_block_array_iterable_native_object) {
  class array_like_native_object
      : public native_object,
        public native_object::array_like,
        public std::enable_shared_from_this<array_like_native_object> {
   public:
    explicit array_like_native_object(array values)
        : values_(std::move(values)) {}

    std::shared_ptr<const native_object::array_like> as_array_like()
        const override {
      return shared_from_this();
    }
    std::size_t size() const override { return values_.size(); }
    const object& at(std::size_t index) const override {
      return values_.at(index);
    }

   private:
    array values_;
  };

  auto factorials = w::map(
      {{"factorials",
        w::make_native_object<array_like_native_object>(array(
            {w::map({{"value", w::i64(1)}}),
             w::map({{"value", w::string("2")}}),
             w::map({{"value", w::i64(6)}}),
             w::map({{"value", w::i64(24)}}),
             w::map({{"value", w::i64(120)}})}))}});
  {
    auto result = render(
        "The factorial function looks like:{{#factorials}}\n"
        "{{value}}{{/factorials}}",
        factorials);
    EXPECT_EQ(
        *result,
        "The factorial function looks like:\n"
        "1\n"
        "2\n"
        "6\n"
        "24\n"
        "120");
  }
  {
    strict_boolean_conditional = diagnostic_level::info;
    auto result = render(
        "The factorial function looks like:\n"
        "{{^factorials}}\n"
        "{{value}}\n"
        "{{/factorials}}",
        factorials);
    EXPECT_EQ(*result, "The factorial function looks like:\n");
  }
}

TEST_F(RenderTest, section_block_map) {
  auto factorials = w::map(
      {{"factorials",
        w::map(
            {{"first", w::i64(1)},
             {"second", w::string("2")},
             {"third", w::i64(6)}})}});
  {
    auto result = render(
        "The factorial function looks like:{{#factorials}}\n"
        "{{first}}\n"
        "{{second}}\n"
        "{{third}}\n"
        "{{/factorials}}",
        factorials);
    EXPECT_EQ(
        *result,
        "The factorial function looks like:\n"
        "1\n"
        "2\n"
        "6\n");
  }
  {
    strict_boolean_conditional = diagnostic_level::info;
    auto result = render(
        "The factorial function looks like:{{^factorials}}\n"
        "{{first}}\n"
        "{{second}}\n"
        "{{third}}\n"
        "{{/factorials}}",
        factorials);
    EXPECT_EQ(*result, "The factorial function looks like:");
  }
}

TEST_F(RenderTest, section_block_map_like_native_object) {
  class map_like_native_object
      : public native_object,
        public native_object::map_like,
        public std::enable_shared_from_this<map_like_native_object> {
   public:
    explicit map_like_native_object(map values) : values_(std::move(values)) {}

    std::shared_ptr<const native_object::map_like> as_map_like()
        const override {
      return shared_from_this();
    }

    const object* lookup_property(std::string_view id) const override {
      if (auto value = values_.find(id); value != values_.end()) {
        return &value->second;
      }
      return nullptr;
    }

   private:
    map values_;
  };

  auto factorials = w::map(
      {{"factorials",
        w::make_native_object<map_like_native_object>(map(
            {{"first", w::i64(1)},
             {"second", w::string("2")},
             {"third", w::i64(6)}}))}});
  {
    auto result = render(
        "The factorial function looks like:{{#factorials}}\n"
        "{{first}}\n"
        "{{second}}\n"
        "{{third}}\n"
        "{{/factorials}}",
        factorials);
    EXPECT_EQ(
        *result,
        "The factorial function looks like:\n"
        "1\n"
        "2\n"
        "6\n");
  }
  {
    strict_boolean_conditional = diagnostic_level::info;
    auto result = render(
        "The factorial function looks like:\n"
        "{{^factorials}}\n"
        "{{first}}\n"
        "{{second}}\n"
        "{{third}}\n"
        "{{/factorials}}",
        factorials);
    EXPECT_EQ(*result, "The factorial function looks like:\n");
  }
}

TEST_F(RenderTest, section_block_pointless_native_object) {
  auto context =
      w::map({{"pointless", w::make_native_object<empty_native_object>()}});
  {
    strict_boolean_conditional = diagnostic_level::info;
    auto result = render(
        "{{#pointless}}\n"
        "Should not be rendered\n"
        "{{/pointless}}",
        context);
    EXPECT_EQ(*result, "");
  }
  {
    strict_boolean_conditional = diagnostic_level::error;
    auto result = render(
        "{{#pointless}}\n"
        "Should not be rendered\n"
        "{{/pointless}}",
        context);
    EXPECT_FALSE(result.has_value());
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Condition 'pointless' is not a boolean. The encountered value is:\n"
            "<native_object>\n",
            path_to_file,
            1)));
  }
}

TEST_F(RenderTest, section_block_empty_array) {
  auto result = render(
      "The factorial function looks like:{{#factorials}}\n"
      "{{value}}\n"
      "{{/factorials}}",
      w::map({{"factorials", w::array({})}}));
  EXPECT_EQ(*result, "The factorial function looks like:");
}

TEST_F(RenderTest, section_block_boolean_condition) {
  {
    auto result = render(
        "{{#news.has-update?}}Stuff is {{foo}} happening!{{/news.has-update?}}",
        w::map(
            {{"news", w::map({{"has-update?", w::boolean(true)}})},
             {"foo", w::string("now")}}));
    EXPECT_EQ(*result, "Stuff is now happening!");
  }
  {
    auto result = render(
        "{{#news.has-update?}}Stuff is {{foo}} happening!{{/news.has-update?}}",
        w::map({{"news", w::map({{"has-update?", w::boolean(false)}})}}));
    EXPECT_EQ(*result, "");
  }
}

TEST_F(RenderTest, section_block_non_boolean_condition_failure) {
  auto result = render(
      "{{#news.has-update?}}Stuff is {{foo}} happening!{{/news.has-update?}}",
      w::map(
          {{"news", w::map({{"has-update?", w::i64(1)}})},
           {"foo", w::string("now")}}));
  EXPECT_FALSE(result.has_value());
  EXPECT_THAT(
      diagnostics(),
      testing::ElementsAre(diagnostic(
          diagnostic_level::error,
          "Condition 'news.has-update?' is not a boolean. The encountered value is:\n"
          "i64(1)\n",
          path_to_file,
          1)));
}

TEST_F(RenderTest, section_block_non_boolean_condition_warning) {
  strict_boolean_conditional = diagnostic_level::warning;

  auto result = render(
      "{{#news.has-update?}}Stuff is {{foo}} happening!{{/news.has-update?}}",
      w::map(
          {{"news", w::map({{"has-update?", w::i64(1)}})},
           {"foo", w::string("now")}}));
  EXPECT_EQ(*result, "Stuff is now happening!");
  EXPECT_THAT(
      diagnostics(),
      testing::ElementsAre(diagnostic(
          diagnostic_level::warning,
          "Condition 'news.has-update?' is not a boolean. The encountered value is:\n"
          "i64(1)\n",
          path_to_file,
          1)));
}

TEST_F(RenderTest, section_block_non_boolean_condition_allowed) {
  strict_boolean_conditional = diagnostic_level::info;

  auto result = render(
      "{{#news.has-update?}}Stuff is {{foo}} happening!{{/news.has-update?}}",
      w::map(
          {{"news", w::map({{"has-update?", w::i64(1)}})},
           {"foo", w::string("now")}}));
  EXPECT_EQ(*result, "Stuff is now happening!");
  EXPECT_THAT(diagnostics(), testing::ElementsAre(/* empty */));
}

TEST_F(RenderTest, section_block_inversion_boolean_condition) {
  {
    auto result = render(
        "{{^news.has-no-update?}}Stuff is {{foo}} happening!{{/news.has-no-update?}}",
        w::map(
            {{"news", w::map({{"has-no-update?", w::boolean(false)}})},
             {"foo", w::string("now")}}));
    EXPECT_EQ(*result, "Stuff is now happening!");
  }
  {
    auto result = render(
        "{{^news.has-no-update?}}Stuff is {{foo}} happening!{{/news.has-no-update?}}",
        w::map({{"news", w::map({{"has-no-update?", w::boolean(true)}})}}));
    EXPECT_EQ(*result, "");
  }
}

TEST_F(RenderTest, section_block_inversion_array) {
  strict_boolean_conditional = diagnostic_level::info;
  auto result = render(
      "The factorial function looks like:\n"
      "{{^factorials}}\n"
      "{{.}}{{/factorials}}",
      w::map(
          {{"factorials",
            w::array(
                {w::i64(1), w::i64(2), w::i64(6), w::i64(24), w::i64(120)})}}));
  EXPECT_EQ(*result, "The factorial function looks like:\n");
}

TEST_F(RenderTest, section_block_inversion_non_boolean_condition_failure) {
  auto result = render(
      "{{^news.has-update?}}Stuff is {{foo}} happening!{{/news.has-update?}}",
      w::map(
          {{"news", w::map({{"has-update?", w::i64(1)}})},
           {"foo", w::string("now")}}));
  EXPECT_FALSE(result.has_value());
  EXPECT_THAT(
      diagnostics(),
      testing::ElementsAre(diagnostic(
          diagnostic_level::error,
          "Condition 'news.has-update?' is not a boolean. The encountered value is:\n"
          "i64(1)\n",
          path_to_file,
          1)));
}

TEST_F(RenderTest, section_block_inversion_non_boolean_condition_warning) {
  strict_boolean_conditional = diagnostic_level::warning;

  auto result = render(
      "{{^news.has-update?}}Stuff is {{foo}} happening!{{/news.has-update?}}",
      w::map(
          {{"news", w::map({{"has-update?", w::i64(0)}})},
           {"foo", w::string("now")}}));
  EXPECT_EQ(*result, "Stuff is now happening!");
  EXPECT_THAT(
      diagnostics(),
      testing::ElementsAre(diagnostic(
          diagnostic_level::warning,
          "Condition 'news.has-update?' is not a boolean. The encountered value is:\n"
          "i64(0)\n",
          path_to_file,
          1)));
}

TEST_F(RenderTest, if_block) {
  {
    auto result = render(
        "{{#if news.has-update?}}\n"
        "Stuff is {{foo}} happening!\n"
        "{{/if news.has-update?}}\n",
        w::map(
            {{"news", w::map({{"has-update?", w::boolean(true)}})},
             {"foo", w::string("now")}}));
    EXPECT_EQ(*result, "Stuff is now happening!\n");
  }
  {
    auto result = render(
        "{{#if news.has-update?}}Stuff is {{foo}} happening!{{/if news.has-update?}}",
        w::map({{"news", w::map({{"has-update?", w::boolean(false)}})}}));
    EXPECT_EQ(*result, "");
  }
}

TEST_F(RenderTest, unless_block) {
  {
    auto result = render(
        "{{#unless news.has-update?}}\n"
        "Stuff is {{foo}} happening!\n"
        "{{/unless news.has-update?}}\n",
        w::map(
            {{"news", w::map({{"has-update?", w::boolean(false)}})},
             {"foo", w::string("now")}}));
    EXPECT_EQ(*result, "Stuff is now happening!\n");
  }
  {
    auto result = render(
        "{{#unless news.has-update?}}Stuff is {{foo}} happening!{{/unless news.has-update?}}",
        w::map({{"news", w::map({{"has-update?", w::boolean(true)}})}}));
    EXPECT_EQ(*result, "");
  }
}

TEST_F(RenderTest, if_else_block) {
  {
    auto result = render(
        "{{#if news.has-update?}}\n"
        "Stuff is {{foo}} happening!\n"
        "{{#else}}\n"
        "Nothing is happening!\n"
        "{{/if news.has-update?}}\n",
        w::map(
            {{"news", w::map({{"has-update?", w::boolean(true)}})},
             {"foo", w::string("now")}}));
    EXPECT_EQ(*result, "Stuff is now happening!\n");
  }
  {
    auto result = render(
        "{{#if news.has-update?}}\n"
        "Stuff is {{foo}} happening!\n"
        "{{#else}}\n"
        "Nothing is happening!\n"
        "{{/if news.has-update?}}\n",
        w::map({{"news", w::map({{"has-update?", w::boolean(false)}})}}));
    EXPECT_EQ(*result, "Nothing is happening!\n");
  }
}

TEST_F(RenderTest, unless_else_block) {
  {
    auto result = render(
        "{{#unless news.has-update?}}\n"
        "Nothing is happening!\n"
        "{{#else}}\n"
        "Stuff is {{foo}} happening!\n"
        "{{/unless news.has-update?}}\n",
        w::map({{"news", w::map({{"has-update?", w::boolean(false)}})}}));
    EXPECT_EQ(*result, "Nothing is happening!\n");
  }
  {
    auto result = render(
        "{{#unless news.has-update?}}\n"
        "Nothing is happening!\n"
        "{{#else}}\n"
        "Stuff is {{foo}} happening!\n"
        "{{/unless news.has-update?}}\n",
        w::map(
            {{"news", w::map({{"has-update?", w::boolean(true)}})},
             {"foo", w::string("now")}}));
    EXPECT_EQ(*result, "Stuff is now happening!\n");
  }
}

TEST_F(RenderTest, if_not_else_block) {
  {
    auto result = render(
        "{{#if (not news.has-update?)}}\n"
        "Nothing is happening!\n"
        "{{#else}}\n"
        "Stuff is {{foo}} happening!\n"
        "{{/if (not news.has-update?)}}\n",
        w::map({{"news", w::map({{"has-update?", w::boolean(false)}})}}));
    EXPECT_THAT(diagnostics(), testing::IsEmpty());
    EXPECT_EQ(*result, "Nothing is happening!\n");
  }
  {
    auto result = render(
        "{{#if (not news.has-update?)}}\n"
        "Nothing is happening!\n"
        "{{#else}}\n"
        "Stuff is {{foo}} happening!\n"
        "{{/if (not news.has-update?)}}\n",
        w::map(
            {{"news", w::map({{"has-update?", w::boolean(true)}})},
             {"foo", w::string("now")}}));
    EXPECT_THAT(diagnostics(), testing::IsEmpty());
    EXPECT_EQ(*result, "Stuff is now happening!\n");
  }
}

TEST_F(RenderTest, printable_types_strict_failure) {
  {
    auto result = render(
        "{{i64}} {{string}}",
        w::map({{"i64", w::i64(-42)}, {"string", w::string("hello")}}));
    EXPECT_EQ(*result, "-42 hello");
  }
  {
    auto result = render("{{f64}}", w::map({{"f64", w::f64(3.1415926)}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Object named 'f64' is not printable. The encountered value is:\n"
            "f64(3.1415926)\n",
            path_to_file,
            1)));
    EXPECT_FALSE(result.has_value());
  }
  {
    auto result = render("{{bool}}", w::map({{"bool", w::boolean(true)}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Object named 'bool' is not printable. The encountered value is:\n"
            "true\n",
            path_to_file,
            1)));
    EXPECT_FALSE(result.has_value());
  }
  {
    auto result = render("{{null_}}", w::map({{"null_", w::null}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Object named 'null_' is not printable. The encountered value is:\n"
            "null\n",
            path_to_file,
            1)));
    EXPECT_FALSE(result.has_value());
  }
  {
    auto result = render("{{array}}", w::map({{"array", w::array({})}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Object named 'array' is not printable. The encountered value is:\n"
            "array (size=0)\n",
            path_to_file,
            1)));
    EXPECT_FALSE(result.has_value());
  }
  {
    auto result = render("{{map}}", w::map({{"map", w::map({})}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Object named 'map' is not printable. The encountered value is:\n"
            "map (size=0)\n",
            path_to_file,
            1)));
    EXPECT_FALSE(result.has_value());
  }
  {
    auto result = render(
        "{{native}}",
        w::map({{"native", w::make_native_object<empty_native_object>()}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Object named 'native' is not printable. The encountered value is:\n"
            "<native_object>\n",
            path_to_file,
            1)));
    EXPECT_FALSE(result.has_value());
  }
}

TEST_F(RenderTest, printable_types_warning) {
  strict_printable_types = diagnostic_level::warning;

  {
    auto result = render(
        "{{i64}} {{string}}",
        w::map({{"i64", w::i64(-42)}, {"string", w::string("hello")}}));
    EXPECT_EQ(*result, "-42 hello");
  }
  {
    auto result = render("{{f64}}", w::map({{"f64", w::f64(3.1415926)}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::warning,
            "Object named 'f64' is not printable. The encountered value is:\n"
            "f64(3.1415926)\n",
            path_to_file,
            1)));
    EXPECT_EQ(*result, "3.1415926");
  }
  {
    auto result = render("{{bool}}", w::map({{"bool", w::boolean(true)}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::warning,
            "Object named 'bool' is not printable. The encountered value is:\n"
            "true\n",
            path_to_file,
            1)));
    EXPECT_EQ(*result, "true");
  }
  {
    auto result = render("{{null_}}", w::map({{"null_", w::null}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::warning,
            "Object named 'null_' is not printable. The encountered value is:\n"
            "null\n",
            path_to_file,
            1)));
    EXPECT_EQ(*result, "");
  }

  // Arrays, maps, native_objects are not printable in any case
  {
    auto result = render("{{array}}", w::map({{"array", w::array({})}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Object named 'array' is not printable. The encountered value is:\n"
            "array (size=0)\n",
            path_to_file,
            1)));
    EXPECT_FALSE(result.has_value());
  }
  {
    auto result = render("{{map}}", w::map({{"map", w::map({})}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Object named 'map' is not printable. The encountered value is:\n"
            "map (size=0)\n",
            path_to_file,
            1)));
    EXPECT_FALSE(result.has_value());
  }
  {
    auto result = render(
        "{{native}}",
        w::map({{"native", w::make_native_object<empty_native_object>()}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Object named 'native' is not printable. The encountered value is:\n"
            "<native_object>\n",
            path_to_file,
            1)));
    EXPECT_FALSE(result.has_value());
  }
}

TEST_F(RenderTest, printable_types_allowed) {
  strict_printable_types = diagnostic_level::info;

  {
    auto result = render(
        "{{i64}} {{string}}",
        w::map({{"i64", w::i64(-42)}, {"string", w::string("hello")}}));
    EXPECT_EQ(*result, "-42 hello");
  }
  {
    auto result = render("{{f64}}", w::map({{"f64", w::f64(3.1415926)}}));
    EXPECT_THAT(diagnostics(), testing::ElementsAre(/* empty */));
    EXPECT_EQ(*result, "3.1415926");
  }
  {
    auto result = render("{{bool}}", w::map({{"bool", w::boolean(true)}}));
    EXPECT_THAT(diagnostics(), testing::ElementsAre(/* empty */));
    EXPECT_EQ(*result, "true");
  }
  {
    auto result = render("{{null_}}", w::map({{"null_", w::null}}));
    EXPECT_THAT(diagnostics(), testing::ElementsAre(/* empty */));
    EXPECT_EQ(*result, "");
  }

  // Arrays, maps, native_objects are not printable in any case
  {
    auto result = render("{{array}}", w::map({{"array", w::array({})}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Object named 'array' is not printable. The encountered value is:\n"
            "array (size=0)\n",
            path_to_file,
            1)));
    EXPECT_FALSE(result.has_value());
  }
  {
    auto result = render("{{map}}", w::map({{"map", w::map({})}}));
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Object named 'map' is not printable. The encountered value is:\n"
            "map (size=0)\n",
            path_to_file,
            1)));
    EXPECT_FALSE(result.has_value());
  }
  {
    auto result = render(
        "{{native}}",
        w::map({{"native", w::make_native_object<empty_native_object>()}}));
    EXPECT_FALSE(result.has_value());
    EXPECT_THAT(
        diagnostics(),
        testing::ElementsAre(diagnostic(
            diagnostic_level::error,
            "Object named 'native' is not printable. The encountered value is:\n"
            "<native_object>\n",
            path_to_file,
            1)));
  }
}

TEST_F(RenderTest, undefined_variables_allowed) {
  strict_undefined_variables = diagnostic_level::info;
  strict_printable_types = diagnostic_level::info;

  auto result = render(
      "{{foo}}\n"
      "{{foo.bar}}\n"
      "{{abc}}\n"
      "{{abc.xyz}}\n",
      w::map({{"abc", w::string("xyz")}}));
  EXPECT_THAT(diagnostics(), testing::ElementsAre(/* empty */));
  EXPECT_EQ(
      *result,
      "\n"
      "\n"
      "xyz\n"
      "\n");
}

TEST_F(RenderTest, partials) {
  auto result = render(
      "{{> some/file /path}}\n"
      "{{#array}}\n"
      "{{>some / file/path }}\n"
      "{{/array}}",
      w::map(
          {{"value", w::i64(1)},
           {"array",
            w::array(
                {w::map({{"value", w::i64(2)}}),
                 w::map({{"value", w::string("foo")}}),
                 w::map({{"value", w::string("bar")}})})}}),
      partials({{"some/file/path", "{{value}} (from partial)\n"}}));
  EXPECT_EQ(
      *result,
      "1 (from partial)\n"
      "2 (from partial)\n"
      "foo (from partial)\n"
      "bar (from partial)\n");
}

TEST_F(RenderTest, partials_missing) {
  auto result = render(
      "{{> some/other/path}}",
      w::map({}),
      partials({{"some/file/path", "{{value}} (from partial)"}}));
  EXPECT_THAT(
      diagnostics(),
      testing::ElementsAre(diagnostic(
          diagnostic_level::error,
          "Partial with path 'some/other/path' was not found",
          path_to_file,
          1)));
  EXPECT_FALSE(result.has_value());
}

TEST_F(RenderTest, partials_no_resolver) {
  auto result = render("{{> some/file/path}}", w::map({}));
  EXPECT_THAT(
      diagnostics(),
      testing::ElementsAre(diagnostic(
          diagnostic_level::error,
          "No partial resolver was provided. Cannot resolve partial with path 'some/file/path'",
          path_to_file,
          1)));
  EXPECT_FALSE(result.has_value());
}

TEST_F(RenderTest, partials_indentation) {
  auto result = render(
      "{{#array}}\n"
      "before\n"
      "  {{>some / file/path }}\n"
      "after\n"
      "{{/array}}",
      w::map(
          {{"array",
            w::array(
                {w::map({{"value", w::i64(2)}}),
                 w::map({{"value", w::string("foo")}}),
                 w::map({{"value", w::string("bar")}})})}}),
      partials(
          {{"some/file/path",
            "{{value}} (from partial)\n"
            "A second line\n"}}));
  EXPECT_EQ(
      *result,
      "before\n"
      "  2 (from partial)\n"
      "  A second line\n"
      "after\n"
      "before\n"
      "  foo (from partial)\n"
      "  A second line\n"
      "after\n"
      "before\n"
      "  bar (from partial)\n"
      "  A second line\n"
      "after\n");
}

TEST_F(RenderTest, partials_indentation_nested) {
  auto result = render(
      "{{#array}}\n"
      "before\n"
      "  {{>partial-1 }}\n"
      "after\n"
      "{{/array}}",
      w::map(
          {{"array",
            w::array({
                w::map({{"value", w::i64(2)}}),
                w::map({{"value", w::string("foo")}}),
            })}}),
      partials(
          {{"partial-1",
            "{{value}} (from partial-1)\n"
            "  nested: {{> partial-2}}\n"},
           {"partial-2",
            "{{value}} (from partial-2)\n"
            "second line from partial-2"}}));
  EXPECT_EQ(
      *result,
      "before\n"
      "  2 (from partial-1)\n"
      "    nested: 2 (from partial-2)\n"
      "  second line from partial-2\n"
      "after\n"
      "before\n"
      "  foo (from partial-1)\n"
      "    nested: foo (from partial-2)\n"
      "  second line from partial-2\n"
      "after\n");
}

TEST_F(RenderTest, partial_apply_preserves_whitespace_offset) {
  auto result = render(
      " \t {{> partial-1}} \t \n",
      w::map({{"value", w::i64(42)}}),
      partials(
          {{"partial-1",
            "\t 1\n"
            " \t {{>partial-2}} \n"},
           {"partial-2",
            "\t 2\n"
            " \t {{>partial-3}}! \n"},
           {"partial-3", "\t{{value}}"}}));
  EXPECT_EQ(
      *result,
      " \t \t 1\n"
      " \t  \t \t 2\n"
      " \t  \t  \t \t42! \n");
}

TEST_F(RenderTest, strip_standalone_lines) {
  auto result = render(
      "| This Is\n"
      "{{#boolean}}\n"
      "|\n"
      "{{/boolean}}\n"
      "| A Line\n",
      w::map({{"boolean", w::boolean(true)}}));
  EXPECT_EQ(
      *result,
      "| This Is\n"
      "|\n"
      "| A Line\n");
}

TEST_F(RenderTest, strip_standalone_lines_indented) {
  auto result = render(
      "| This Is\n"
      "  {{#boolean}}\n"
      "|\n"
      "  {{/boolean}}\n"
      "| A Line\n",
      w::map({{"boolean", w::boolean(true)}}));
  EXPECT_EQ(
      *result,
      "| This Is\n"
      "|\n"
      "| A Line\n");
}

TEST_F(RenderTest, strip_standalone_lines_multiple) {
  auto result = render(
      "| This Is\n"
      "  {{#boolean}} {{#boolean}} \n"
      "|\n"
      "  {{/boolean}}\n"
      "  {{/boolean}}\n"
      "| A Line\n",
      w::map({{"boolean", w::boolean(true)}}));
  EXPECT_EQ(
      *result,
      "| This Is\n"
      "|\n"
      "| A Line\n");
}

TEST_F(RenderTest, strip_standalone_lines_multiline) {
  auto result = render(
      "| This Is\n"
      "  {{#boolean\n"
      "       .condition}}  \n"
      "|\n"
      "  {{/boolean.condition}}\n"
      "| A Line\n",
      w::map({{"boolean", w::map({{"condition", w::boolean(true)}})}}));
  EXPECT_EQ(
      *result,
      "| This Is\n"
      "|\n"
      "| A Line\n");
}

TEST_F(RenderTest, strip_standalone_lines_multiline_comment) {
  auto result = render(
      "| This Is\n"
      "  {{^boolean\n"
      "       .condition}} {{! unaffected }} \n"
      "|\n"
      "  {{/boolean.condition}}\n"
      "| A Line\n",
      w::map({{"boolean", w::map({{"condition", w::boolean(false)}})}}));
  EXPECT_EQ(
      *result,
      "| This Is\n"
      "|\n"
      "| A Line\n");
}

TEST_F(RenderTest, strip_standalone_lines_multiline_ineligible) {
  auto result = render(
      "| This Is\n"
      "  {{#boolean\n"
      "       .condition}} {{ineligible}} \n"
      "|\n"
      "  {{/boolean.condition}}\n"
      "| A Line\n",
      w::map(
          {{"ineligible", w::string("")},
           {"boolean", w::map({{"condition", w::boolean(true)}})}}));
  EXPECT_EQ(
      *result,
      "| This Is\n"
      "    \n"
      "|\n"
      "| A Line\n");
}

TEST_F(
    RenderTest,
    strip_standalone_lines_multiline_ineligible_partial_application) {
  auto result = render(
      "| This Is\n"
      "  {{#boolean\n"
      "       .condition}} {{> ineligible}} \n"
      "|\n"
      "  {{/boolean.condition}}\n"
      "| A Line\n",
      w::map(
          {{"value", w::i64(5)},
           {"boolean", w::map({{"condition", w::boolean(true)}})}}),
      partials({{"ineligible", "{{value}} (from partial)\n"}}));
  EXPECT_EQ(
      *result,
      "| This Is\n"
      "   5 (from partial)\n"
      " \n"
      "|\n"
      "| A Line\n");
}

TEST_F(RenderTest, globals) {
  auto result = render(
      "{{global}}\n"
      "{{#array}}\n"
      "{{.}} — {{global-2}}\n"
      "{{/array}}\n",
      w::map({{"array", w::array({w::i64(1), w::i64(2)})}}),
      partials({}),
      globals(
          {{"global", w::string("hello")}, {"global-2", w::string("hello!")}}));
  EXPECT_EQ(
      *result,
      "hello\n"
      "1 — hello!\n"
      "2 — hello!\n");
}

TEST_F(RenderTest, globals_shadowing) {
  auto result = render(
      "{{global}}\n",
      w::map({{"global", w::string("good")}}),
      partials({}),
      globals({{"global", w::string("bad")}}));
  EXPECT_EQ(*result, "good\n");
}

} // namespace whisker
