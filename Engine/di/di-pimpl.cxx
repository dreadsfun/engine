// Copyright (c) 2005-2011 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD/e, an XML Schema
// to C++ data binding compiler for embedded systems.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
//

// Begin prologue.
//
//
// End prologue.

#include "di-pimpl.hxx"

#include <xsde/cxx/parser/validating/string-common.hxx>

// param_class_type_pimpl
//

param_class_type_pimpl::
param_class_type_pimpl ()
: param_class_type_pskel (0)
{
}

void param_class_type_pimpl::
pre ()
{
  this->param_class_type_pimpl_state_.str_.clear ();
}

void param_class_type_pimpl::
_characters (const ::xsde::cxx::ro_string& s)
{
  if (this->_facets ().whitespace_ == 2 &&
      this->param_class_type_pimpl_state_.str_.size () == 0)
  {
    ::xsde::cxx::ro_string tmp (s.data (), s.size ());

    if (::xsde::cxx::trim_left (tmp) != 0)
    {
      this->param_class_type_pimpl_state_.str_ += tmp;
    }
  }
  else
    this->param_class_type_pimpl_state_.str_ += s;
}

void param_class_type_pimpl::
_post ()
{
  ::xsde::cxx::parser::validating::string_common::validate_facets (
    this->param_class_type_pimpl_state_.str_,
    this->_facets (),
    this->_context ());
}

::param_class_type param_class_type_pimpl::
post_param_class_type ()
{
  ::param_class_type::value_type v =
  static_cast< ::param_class_type::value_type > (0);
  const char* s = this->param_class_type_pimpl_state_.str_.c_str ();

  if (strcmp (s, "char") == 0)
    v = ::param_class_type::char_;
  else if (strcmp (s, "unsigned char") == 0)
    v = ::param_class_type::unsigned_char;
  else if (strcmp (s, "int") == 0)
    v = ::param_class_type::int_;
  else if (strcmp (s, "unsigned int") == 0)
    v = ::param_class_type::unsigned_int;
  else if (strcmp (s, "long") == 0)
    v = ::param_class_type::long_;
  else if (strcmp (s, "double") == 0)
    v = ::param_class_type::double_;
  else if (strcmp (s, "bool") == 0)
    v = ::param_class_type::bool_;
  else if (strcmp (s, "string") == 0)
    v = ::param_class_type::string;

  ::param_class_type r (v);
  return r;
}

// insert_pimpl
//

void insert_pimpl::
pre ()
{
  this->insert_pimpl_state_.insert_ = ::insert ();
}

void insert_pimpl::
value (const ::std::string& x)
{
  this->insert_pimpl_state_.insert_.value (x);
}

::insert insert_pimpl::
post_insert ()
{
  return this->insert_pimpl_state_.insert_;
}

// attribute_type_pimpl
//

attribute_type_pimpl::
attribute_type_pimpl (bool b)
{
  this->attribute_type_pimpl_base_ = b;
  this->attribute_type_pimpl_state_.attribute_type_ = 0;
}

attribute_type_pimpl::
~attribute_type_pimpl ()
{
  if (!this->attribute_type_pimpl_base_ && this->attribute_type_pimpl_state_.attribute_type_)
    delete this->attribute_type_pimpl_state_.attribute_type_;
}

void attribute_type_pimpl::
_reset ()
{
  attribute_type_pskel::_reset ();

  if (!this->attribute_type_pimpl_base_ && this->attribute_type_pimpl_state_.attribute_type_)
  {
    delete this->attribute_type_pimpl_state_.attribute_type_;
    this->attribute_type_pimpl_state_.attribute_type_ = 0;
  }
}

void attribute_type_pimpl::
pre_impl (::attribute_type* x)
{
  this->attribute_type_pimpl_state_.attribute_type_ = x;
}

void attribute_type_pimpl::
pre ()
{
  ::attribute_type* x = new ::attribute_type;
  this->pre_impl (x);
}

void attribute_type_pimpl::
name (const ::std::string& x)
{
  this->attribute_type_pimpl_state_.attribute_type_->name (x);
}

void attribute_type_pimpl::
value (const ::std::string& x)
{
  this->attribute_type_pimpl_state_.attribute_type_->value (x);
}

void attribute_type_pimpl::
insert (const ::insert& x)
{
  this->attribute_type_pimpl_state_.attribute_type_->insert ().push_back (x);
}

::attribute_type* attribute_type_pimpl::
post_attribute_type ()
{
  ::attribute_type* r = this->attribute_type_pimpl_state_.attribute_type_;
  this->attribute_type_pimpl_state_.attribute_type_ = 0;
  return r;
}

// param_type_pimpl
//

void param_type_pimpl::
pre ()
{
  this->param_type_pimpl_state_.param_type_ = ::param_type ();
}

void param_type_pimpl::
type (const ::param_class_type& x)
{
  this->param_type_pimpl_state_.param_type_.type (x);
}

void param_type_pimpl::
value (const ::std::string& x)
{
  this->param_type_pimpl_state_.param_type_.value (x);
}

::param_type param_type_pimpl::
post_param_type ()
{
  return this->param_type_pimpl_state_.param_type_;
}

// inject_one_type_pimpl
//

void inject_one_type_pimpl::
pre ()
{
  this->inject_one_type_pimpl_state_.inject_one_type_ = ::inject_one_type ();
}

void inject_one_type_pimpl::
injection (const ::std::string& x)
{
  this->inject_one_type_pimpl_state_.inject_one_type_.injection (x);
}

void inject_one_type_pimpl::
slot (const ::std::string& x)
{
  this->inject_one_type_pimpl_state_.inject_one_type_.slot (x);
}

::inject_one_type inject_one_type_pimpl::
post_inject_one_type ()
{
  return this->inject_one_type_pimpl_state_.inject_one_type_;
}

// inject_all_type_pimpl
//

void inject_all_type_pimpl::
pre ()
{
  this->inject_all_type_pimpl_state_.inject_all_type_ = ::inject_all_type ();
}

void inject_all_type_pimpl::
receiver (const ::std::string& x)
{
  this->inject_all_type_pimpl_state_.inject_all_type_.receiver (x);
}

void inject_all_type_pimpl::
slot (const ::std::string& x)
{
  this->inject_all_type_pimpl_state_.inject_all_type_.slot (x);
}

::inject_all_type inject_all_type_pimpl::
post_inject_all_type ()
{
  return this->inject_all_type_pimpl_state_.inject_all_type_;
}

// component_pimpl
//

component_pimpl::
component_pimpl (bool b)
{
  this->component_pimpl_base_ = b;
  this->component_pimpl_state_.component_ = 0;
}

component_pimpl::
~component_pimpl ()
{
  if (!this->component_pimpl_base_ && this->component_pimpl_state_.component_)
    delete this->component_pimpl_state_.component_;
}

void component_pimpl::
_reset ()
{
  component_pskel::_reset ();

  if (!this->component_pimpl_base_ && this->component_pimpl_state_.component_)
  {
    delete this->component_pimpl_state_.component_;
    this->component_pimpl_state_.component_ = 0;
  }
}

void component_pimpl::
pre_impl (::component* x)
{
  this->component_pimpl_state_.component_ = x;
}

void component_pimpl::
pre ()
{
  ::component* x = new ::component;
  this->pre_impl (x);
}

void component_pimpl::
name (const ::std::string& x)
{
  this->component_pimpl_state_.component_->name (x);
}

void component_pimpl::
class_ (const ::std::string& x)
{
  this->component_pimpl_state_.component_->class_ (x);
}

void component_pimpl::
attribute (::attribute_type* x)
{
  this->component_pimpl_state_.component_->attribute ().push_back (x);
}

::component* component_pimpl::
post_component ()
{
  ::component* r = this->component_pimpl_state_.component_;
  this->component_pimpl_state_.component_ = 0;
  return r;
}

// inject_pimpl
//

void inject_pimpl::
pre ()
{
  this->inject_pimpl_state_.inject_ = ::inject ();
}

void inject_pimpl::
receiver (const ::std::string& x)
{
  this->inject_pimpl_state_.inject_.receiver (x);
}

void inject_pimpl::
injection (const ::std::string& x)
{
  this->inject_pimpl_state_.inject_.injection (x);
}

void inject_pimpl::
slot (const ::std::string& x)
{
  this->inject_pimpl_state_.inject_.slot (x);
}

::inject inject_pimpl::
post_inject ()
{
  return this->inject_pimpl_state_.inject_;
}

// inject_one_pimpl
//

inject_one_pimpl::
inject_one_pimpl (bool b)
{
  this->inject_one_pimpl_base_ = b;
  this->inject_one_pimpl_state_.inject_one_ = 0;
}

inject_one_pimpl::
~inject_one_pimpl ()
{
  if (!this->inject_one_pimpl_base_ && this->inject_one_pimpl_state_.inject_one_)
    delete this->inject_one_pimpl_state_.inject_one_;
}

void inject_one_pimpl::
_reset ()
{
  inject_one_pskel::_reset ();

  if (!this->inject_one_pimpl_base_ && this->inject_one_pimpl_state_.inject_one_)
  {
    delete this->inject_one_pimpl_state_.inject_one_;
    this->inject_one_pimpl_state_.inject_one_ = 0;
  }
}

void inject_one_pimpl::
pre_impl (::inject_one* x)
{
  this->inject_one_pimpl_state_.inject_one_ = x;
}

void inject_one_pimpl::
pre ()
{
  ::inject_one* x = new ::inject_one;
  this->pre_impl (x);
}

void inject_one_pimpl::
receiver (const ::std::string& x)
{
  this->inject_one_pimpl_state_.inject_one_->receiver (x);
}

void inject_one_pimpl::
inject (const ::inject_one_type& x)
{
  this->inject_one_pimpl_state_.inject_one_->inject ().push_back (x);
}

::inject_one* inject_one_pimpl::
post_inject_one ()
{
  ::inject_one* r = this->inject_one_pimpl_state_.inject_one_;
  this->inject_one_pimpl_state_.inject_one_ = 0;
  return r;
}

// inject_all_pimpl
//

inject_all_pimpl::
inject_all_pimpl (bool b)
{
  this->inject_all_pimpl_base_ = b;
  this->inject_all_pimpl_state_.inject_all_ = 0;
}

inject_all_pimpl::
~inject_all_pimpl ()
{
  if (!this->inject_all_pimpl_base_ && this->inject_all_pimpl_state_.inject_all_)
    delete this->inject_all_pimpl_state_.inject_all_;
}

void inject_all_pimpl::
_reset ()
{
  inject_all_pskel::_reset ();

  if (!this->inject_all_pimpl_base_ && this->inject_all_pimpl_state_.inject_all_)
  {
    delete this->inject_all_pimpl_state_.inject_all_;
    this->inject_all_pimpl_state_.inject_all_ = 0;
  }
}

void inject_all_pimpl::
pre_impl (::inject_all* x)
{
  this->inject_all_pimpl_state_.inject_all_ = x;
}

void inject_all_pimpl::
pre ()
{
  ::inject_all* x = new ::inject_all;
  this->pre_impl (x);
}

void inject_all_pimpl::
injection (const ::std::string& x)
{
  this->inject_all_pimpl_state_.inject_all_->injection (x);
}

void inject_all_pimpl::
inject (const ::inject_all_type& x)
{
  this->inject_all_pimpl_state_.inject_all_->inject ().push_back (x);
}

::inject_all* inject_all_pimpl::
post_inject_all ()
{
  ::inject_all* r = this->inject_all_pimpl_state_.inject_all_;
  this->inject_all_pimpl_state_.inject_all_ = 0;
  return r;
}

// inject_slot_pimpl
//

void inject_slot_pimpl::
pre ()
{
  this->inject_slot_pimpl_state_.inject_slot_ = ::inject_slot ();
}

void inject_slot_pimpl::
slot (const ::std::string& x)
{
  this->inject_slot_pimpl_state_.inject_slot_.slot (x);
}

void inject_slot_pimpl::
injection (const ::std::string& x)
{
  this->inject_slot_pimpl_state_.inject_slot_.injection (x);
}

::inject_slot inject_slot_pimpl::
post_inject_slot ()
{
  return this->inject_slot_pimpl_state_.inject_slot_;
}

// DI_pimpl
//

DI_pimpl::
DI_pimpl (bool b)
{
  this->DI_pimpl_base_ = b;
  this->DI_pimpl_state_.DI_ = 0;
}

DI_pimpl::
~DI_pimpl ()
{
  if (!this->DI_pimpl_base_ && this->DI_pimpl_state_.DI_)
    delete this->DI_pimpl_state_.DI_;
}

void DI_pimpl::
_reset ()
{
  DI_pskel::_reset ();

  if (!this->DI_pimpl_base_ && this->DI_pimpl_state_.DI_)
  {
    delete this->DI_pimpl_state_.DI_;
    this->DI_pimpl_state_.DI_ = 0;
  }
}

void DI_pimpl::
pre_impl (::DI* x)
{
  this->DI_pimpl_state_.DI_ = x;
}

void DI_pimpl::
pre ()
{
  ::DI* x = new ::DI;
  this->pre_impl (x);
}

void DI_pimpl::
plugins (::plugins* x)
{
  this->DI_pimpl_state_.DI_->plugins (x);
}

void DI_pimpl::
components (::components* x)
{
  this->DI_pimpl_state_.DI_->components (x);
}

void DI_pimpl::
wiring (::wiring* x)
{
  this->DI_pimpl_state_.DI_->wiring (x);
}

::DI* DI_pimpl::
post_DI ()
{
  ::DI* r = this->DI_pimpl_state_.DI_;
  this->DI_pimpl_state_.DI_ = 0;
  return r;
}

// shared_pimpl
//

void shared_pimpl::
pre ()
{
  this->shared_pimpl_state_.shared_ = ::shared ();
}

void shared_pimpl::
lib (const ::std::string& x)
{
  this->shared_pimpl_state_.shared_.lib (x);
}

::shared shared_pimpl::
post_shared ()
{
  return this->shared_pimpl_state_.shared_;
}

// plugins_pimpl
//

plugins_pimpl::
plugins_pimpl (bool b)
{
  this->plugins_pimpl_base_ = b;
  this->plugins_pimpl_state_.plugins_ = 0;
}

plugins_pimpl::
~plugins_pimpl ()
{
  if (!this->plugins_pimpl_base_ && this->plugins_pimpl_state_.plugins_)
    delete this->plugins_pimpl_state_.plugins_;
}

void plugins_pimpl::
_reset ()
{
  plugins_pskel::_reset ();

  if (!this->plugins_pimpl_base_ && this->plugins_pimpl_state_.plugins_)
  {
    delete this->plugins_pimpl_state_.plugins_;
    this->plugins_pimpl_state_.plugins_ = 0;
  }
}

void plugins_pimpl::
pre_impl (::plugins* x)
{
  this->plugins_pimpl_state_.plugins_ = x;
}

void plugins_pimpl::
pre ()
{
  ::plugins* x = new ::plugins;
  this->pre_impl (x);
}

void plugins_pimpl::
shared (const ::shared& x)
{
  this->plugins_pimpl_state_.plugins_->shared ().push_back (x);
}

::plugins* plugins_pimpl::
post_plugins ()
{
  ::plugins* r = this->plugins_pimpl_state_.plugins_;
  this->plugins_pimpl_state_.plugins_ = 0;
  return r;
}

// components_pimpl
//

components_pimpl::
components_pimpl (bool b)
{
  this->components_pimpl_base_ = b;
  this->components_pimpl_state_.components_ = 0;
}

components_pimpl::
~components_pimpl ()
{
  if (!this->components_pimpl_base_ && this->components_pimpl_state_.components_)
    delete this->components_pimpl_state_.components_;
}

void components_pimpl::
_reset ()
{
  components_pskel::_reset ();

  if (!this->components_pimpl_base_ && this->components_pimpl_state_.components_)
  {
    delete this->components_pimpl_state_.components_;
    this->components_pimpl_state_.components_ = 0;
  }
}

void components_pimpl::
pre_impl (::components* x)
{
  this->components_pimpl_state_.components_ = x;
}

void components_pimpl::
pre ()
{
  ::components* x = new ::components;
  this->pre_impl (x);
}

void components_pimpl::
component (::component* x)
{
  this->components_pimpl_state_.components_->component ().push_back (x);
}

::components* components_pimpl::
post_components ()
{
  ::components* r = this->components_pimpl_state_.components_;
  this->components_pimpl_state_.components_ = 0;
  return r;
}

// wiring_pimpl
//

wiring_pimpl::
wiring_pimpl (bool b)
{
  this->wiring_pimpl_base_ = b;
  this->wiring_pimpl_state_.wiring_ = 0;
}

wiring_pimpl::
~wiring_pimpl ()
{
  if (!this->wiring_pimpl_base_ && this->wiring_pimpl_state_.wiring_)
    delete this->wiring_pimpl_state_.wiring_;
}

void wiring_pimpl::
_reset ()
{
  wiring_pskel::_reset ();

  if (!this->wiring_pimpl_base_ && this->wiring_pimpl_state_.wiring_)
  {
    delete this->wiring_pimpl_state_.wiring_;
    this->wiring_pimpl_state_.wiring_ = 0;
  }
}

void wiring_pimpl::
pre_impl (::wiring* x)
{
  this->wiring_pimpl_state_.wiring_ = x;
}

void wiring_pimpl::
pre ()
{
  ::wiring* x = new ::wiring;
  this->pre_impl (x);
}

void wiring_pimpl::
inject (const ::inject& x)
{
  this->wiring_pimpl_state_.wiring_->inject ().push_back (x);
}

void wiring_pimpl::
inject_all (::inject_all* x)
{
  this->wiring_pimpl_state_.wiring_->inject_all ().push_back (x);
}

void wiring_pimpl::
inject_one (::inject_one* x)
{
  this->wiring_pimpl_state_.wiring_->inject_one ().push_back (x);
}

void wiring_pimpl::
inject_slot (const ::inject_slot& x)
{
  this->wiring_pimpl_state_.wiring_->inject_slot ().push_back (x);
}

::wiring* wiring_pimpl::
post_wiring ()
{
  ::wiring* r = this->wiring_pimpl_state_.wiring_;
  this->wiring_pimpl_state_.wiring_ = 0;
  return r;
}

// DI_paggr
//

DI_paggr::
DI_paggr ()
{
  this->component_p_.parsers (this->token_p_,
                              this->token_p_,
                              this->attribute_type_p_);

  this->inject_p_.parsers (this->token_p_,
                           this->token_p_,
                           this->token_p_);

  this->inject_one_type_p_.parsers (this->token_p_,
                                    this->token_p_);

  this->inject_one_p_.parsers (this->token_p_,
                               this->inject_one_type_p_);

  this->inject_all_type_p_.parsers (this->token_p_,
                                    this->token_p_);

  this->inject_all_p_.parsers (this->token_p_,
                               this->inject_all_type_p_);

  this->inject_slot_p_.parsers (this->token_p_,
                                this->token_p_);

  this->DI_p_.parsers (this->plugins_p_,
                       this->components_p_,
                       this->wiring_p_);

  this->plugins_p_.parsers (this->shared_p_);

  this->shared_p_.parsers (this->name_p_);

  this->components_p_.parsers (this->component_p_);

  this->wiring_p_.parsers (this->inject_p_,
                           this->inject_all_p_,
                           this->inject_one_p_,
                           this->inject_slot_p_);

  this->attribute_type_p_.parsers (this->token_p_,
                                   this->string_p_,
                                   this->insert_p_);

  this->insert_p_.parsers (this->string_p_);
}

const char* DI_paggr::
root_name ()
{
  return "DI";
}

const char* DI_paggr::
root_namespace ()
{
  return "";
}

// Begin epilogue.
//
//
// End epilogue.

