#include "../HTML Decode/processHTMLCode.h"
#include "stdafx.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(HtmlDecode_function)

// Возвращает пустую строку, если введенная строка пустая
BOOST_AUTO_TEST_CASE(return_empty_string_if_input_empty_string)
{
	BOOST_CHECK_EQUAL(HtmlDecode(""), "");
}

// Возвращает без изменения незавершенные html-сущности
BOOST_AUTO_TEST_CASE(return_without_changing_the_incomplete_html_entity)
{
	BOOST_CHECK_EQUAL(HtmlDecode("Hello crawnberry &apos &quot &gt &lt &amp"), "Hello crawnberry &apos &quot &gt &lt &amp");
}

// Возвращает строку с заменой html тегов на соответствующие символы
BOOST_AUTO_TEST_CASE(return_string_replacement_of_html_tags_by_the_appropriate_characters)
{
	BOOST_CHECK_EQUAL(HtmlDecode("This is my &quot; quote &quot;. It&apos;s awsome and more &lt;&lt; bigger than that &gt; small &amp; apostrophe"), "This is my \" quote \". It`s awsome and more << bigger than that > small & apostrophe");
}

// Проверка всех html-сущностей установленных друг за другом
BOOST_AUTO_TEST_CASE(check_all_the_html_entities_placed_for_each_other)
{
	BOOST_CHECK_EQUAL(HtmlDecode("&apos;&quot;&gt;&lt;&amp;"), "`\"><&");
}

// Корректная работа функции при содержании как законченных, так и не законченных html-сущностей
BOOST_AUTO_TEST_CASE(сorrect_work_of_function_when_string_content_is_as_complete_and_not_complete_html_entities)
{
	BOOST_CHECK_EQUAL(HtmlDecode("We love our&apos;s &quot; world &gt&lt&amp; and so much, we &gt; love &lt; the universe&amp"), "We love our`s \" world &gt&lt& and so much, we > love < the universe&amp");
}
BOOST_AUTO_TEST_SUITE_END()