//this file is generated by program(drogon_ctl) automatically,don't modify it!
#include "contact.h"
#include <drogon/utils/OStringStream.h>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <deque>
#include <queue>

#include "../models/contact.hpp"

std::string contact::genText(const DrTemplateData& contact_view_data)
{
	drogon::OStringStream contact_tmp_stream;
	std::string layoutName{""};
    using namespace dws::models;
    auto c=contact_view_data.get<Contact>("contact");
	contact_tmp_stream << "<h2>";
contact_tmp_stream<<c.FirstName;
	contact_tmp_stream << " ";
contact_tmp_stream<<c.LastName;
	contact_tmp_stream << "</h2>\n";
	contact_tmp_stream << "<div>\n";
	contact_tmp_stream << "  <div>Phone: ";
contact_tmp_stream<<c.Phone;
	contact_tmp_stream << "</div>\n";
	contact_tmp_stream << "  <div>Email: ";
contact_tmp_stream<<c.EMail;
	contact_tmp_stream << "</div>\n";
	contact_tmp_stream << "</div>\n";
contact_tmp_stream<<"\n";
	contact_tmp_stream << "<p>\n";
	contact_tmp_stream << "<button class=\"btn btn-primary\"\n";
	contact_tmp_stream << "      hx-get=\"/contacts/";
contact_tmp_stream<<c.ID;
	contact_tmp_stream << "/edit\"\n";
	contact_tmp_stream << "      hx-target=\"#main\"\n";
	contact_tmp_stream << "      hx-swap=\"innerHTML\">Edit</button>\n";
	contact_tmp_stream << "<button class=\"btn btn-danger\"\n";
	contact_tmp_stream << "      href=\"#\"\n";
	contact_tmp_stream << "      hx-get=\"/contacts/";
contact_tmp_stream<<c.ID;
	contact_tmp_stream << "/delete\"\n";
	contact_tmp_stream << "      hx-target=\"#main\"\n";
	contact_tmp_stream << "      hx-confirm=\"Are you sure you wish to delete this contact?\"\n";
	contact_tmp_stream << "      hx-swap=\"innerHTML\">Delete</button>\n";
	contact_tmp_stream << "<button class=\"btn btn-info\"\n";
	contact_tmp_stream << "      hx-get=\"/contacts\"\n";
	contact_tmp_stream << "      hx-target=\"#main\"\n";
	contact_tmp_stream << "      hx-swap=\"innerHTML\">Back</button>\n";
	contact_tmp_stream << "</p>\n";
if(layoutName.empty())
{
std::string ret{std::move(contact_tmp_stream.str())};
return ret;
}else
{
auto templ = DrTemplateBase::newTemplate(layoutName);
if(!templ) return "";
HttpViewData data;
auto str = std::move(contact_tmp_stream.str());
if(!str.empty() && str[str.length()-1] == '\n') str.resize(str.length()-1);
data[""] = std::move(str);
return templ->genText(data);
}
}
