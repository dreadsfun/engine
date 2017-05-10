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

#include "scene-sskel.hxx"

// vec3_type_sskel
//

void vec3_type_sskel::
x_serializer (::xml_schema::float_sskel& x)
{
  this->x_serializer_ = &x;
}

void vec3_type_sskel::
y_serializer (::xml_schema::float_sskel& y)
{
  this->y_serializer_ = &y;
}

void vec3_type_sskel::
z_serializer (::xml_schema::float_sskel& z)
{
  this->z_serializer_ = &z;
}

void vec3_type_sskel::
serializers (::xml_schema::float_sskel& x,
             ::xml_schema::float_sskel& y,
             ::xml_schema::float_sskel& z)
{
  this->x_serializer_ = &x;
  this->y_serializer_ = &y;
  this->z_serializer_ = &z;
}

vec3_type_sskel::
vec3_type_sskel ()
: vec3_type_impl_ (0),
  x_serializer_ (0),
  y_serializer_ (0),
  z_serializer_ (0)
{
}

vec3_type_sskel::
vec3_type_sskel (vec3_type_sskel* impl, void*)
: ::xsde::cxx::serializer::validating::complex_content (impl, 0),
  vec3_type_impl_ (impl),
  x_serializer_ (0),
  y_serializer_ (0),
  z_serializer_ (0)
{
}

// vec4_type_sskel
//

void vec4_type_sskel::
x_serializer (::xml_schema::float_sskel& x)
{
  this->x_serializer_ = &x;
}

void vec4_type_sskel::
y_serializer (::xml_schema::float_sskel& y)
{
  this->y_serializer_ = &y;
}

void vec4_type_sskel::
z_serializer (::xml_schema::float_sskel& z)
{
  this->z_serializer_ = &z;
}

void vec4_type_sskel::
w_serializer (::xml_schema::float_sskel& w)
{
  this->w_serializer_ = &w;
}

void vec4_type_sskel::
serializers (::xml_schema::float_sskel& x,
             ::xml_schema::float_sskel& y,
             ::xml_schema::float_sskel& z,
             ::xml_schema::float_sskel& w)
{
  this->x_serializer_ = &x;
  this->y_serializer_ = &y;
  this->z_serializer_ = &z;
  this->w_serializer_ = &w;
}

vec4_type_sskel::
vec4_type_sskel ()
: vec4_type_impl_ (0),
  x_serializer_ (0),
  y_serializer_ (0),
  z_serializer_ (0),
  w_serializer_ (0)
{
}

vec4_type_sskel::
vec4_type_sskel (vec4_type_sskel* impl, void*)
: ::xsde::cxx::serializer::validating::complex_content (impl, 0),
  vec4_type_impl_ (impl),
  x_serializer_ (0),
  y_serializer_ (0),
  z_serializer_ (0),
  w_serializer_ (0)
{
}

// scene_graph_sskel
//

void scene_graph_sskel::
nodes_serializer (::nodes_sskel& s)
{
  this->nodes_serializer_ = &s;
}

void scene_graph_sskel::
scenes_serializer (::scenes_sskel& s)
{
  this->scenes_serializer_ = &s;
}

void scene_graph_sskel::
serializers (::nodes_sskel& nodes,
             ::scenes_sskel& scenes)
{
  this->nodes_serializer_ = &nodes;
  this->scenes_serializer_ = &scenes;
}

scene_graph_sskel::
scene_graph_sskel ()
: scene_graph_impl_ (0),
  nodes_serializer_ (0),
  scenes_serializer_ (0)
{
}

scene_graph_sskel::
scene_graph_sskel (scene_graph_sskel* impl, void*)
: ::xsde::cxx::serializer::validating::complex_content (impl, 0),
  scene_graph_impl_ (impl),
  nodes_serializer_ (0),
  scenes_serializer_ (0)
{
}

// nodes_sskel
//

void nodes_sskel::
node_serializer (::node_sskel& s)
{
  this->node_serializer_ = &s;
}

void nodes_sskel::
serializers (::node_sskel& node)
{
  this->node_serializer_ = &node;
}

nodes_sskel::
nodes_sskel ()
: nodes_impl_ (0),
  node_serializer_ (0)
{
}

nodes_sskel::
nodes_sskel (nodes_sskel* impl, void*)
: ::xsde::cxx::serializer::validating::complex_content (impl, 0),
  nodes_impl_ (impl),
  node_serializer_ (0)
{
}

// scene_sskel
//

void scene_sskel::
name_serializer (::xml_schema::token_sskel& name)
{
  this->name_serializer_ = &name;
}

void scene_sskel::
graph_serializer (::xml_schema::string_sskel& graph)
{
  this->graph_serializer_ = &graph;
}

void scene_sskel::
serializers (::xml_schema::token_sskel& name,
             ::xml_schema::string_sskel& graph)
{
  this->name_serializer_ = &name;
  this->graph_serializer_ = &graph;
}

scene_sskel::
scene_sskel ()
: scene_impl_ (0),
  name_serializer_ (0),
  graph_serializer_ (0)
{
}

scene_sskel::
scene_sskel (scene_sskel* impl, void*)
: ::xsde::cxx::serializer::validating::complex_content (impl, 0),
  scene_impl_ (impl),
  name_serializer_ (0),
  graph_serializer_ (0)
{
}

// scenes_sskel
//

void scenes_sskel::
scene_serializer (::scene_sskel& s)
{
  this->scene_serializer_ = &s;
}

void scenes_sskel::
serializers (::scene_sskel& scene)
{
  this->scene_serializer_ = &scene;
}

scenes_sskel::
scenes_sskel ()
: scenes_impl_ (0),
  scene_serializer_ (0)
{
}

scenes_sskel::
scenes_sskel (scenes_sskel* impl, void*)
: ::xsde::cxx::serializer::validating::complex_content (impl, 0),
  scenes_impl_ (impl),
  scene_serializer_ (0)
{
}

// attribute_sskel
//

void attribute_sskel::
name_serializer (::xml_schema::token_sskel& name)
{
  this->name_serializer_ = &name;
}

void attribute_sskel::
value_serializer (::xml_schema::string_sskel& value)
{
  this->value_serializer_ = &value;
}

void attribute_sskel::
serializers (::xml_schema::token_sskel& name,
             ::xml_schema::string_sskel& value)
{
  this->name_serializer_ = &name;
  this->value_serializer_ = &value;
}

attribute_sskel::
attribute_sskel ()
: attribute_impl_ (0),
  name_serializer_ (0),
  value_serializer_ (0)
{
}

attribute_sskel::
attribute_sskel (attribute_sskel* impl, void*)
: ::xsde::cxx::serializer::validating::complex_content (impl, 0),
  attribute_impl_ (impl),
  name_serializer_ (0),
  value_serializer_ (0)
{
}

// node_sskel
//

void node_sskel::
name_serializer (::xml_schema::token_sskel& name)
{
  this->name_serializer_ = &name;
}

void node_sskel::
class__serializer (::xml_schema::token_sskel& class_)
{
  this->class__serializer_ = &class_;
}

void node_sskel::
position_serializer (::vec3_type_sskel& s)
{
  this->position_serializer_ = &s;
}

void node_sskel::
rotation_serializer (::vec4_type_sskel& s)
{
  this->rotation_serializer_ = &s;
}

void node_sskel::
scale_serializer (::vec3_type_sskel& s)
{
  this->scale_serializer_ = &s;
}

void node_sskel::
attribute_serializer (::attribute_sskel& s)
{
  this->attribute_serializer_ = &s;
}

void node_sskel::
serializers (::xml_schema::token_sskel& name,
             ::xml_schema::token_sskel& class_,
             ::vec3_type_sskel& position,
             ::vec4_type_sskel& rotation,
             ::vec3_type_sskel& scale,
             ::attribute_sskel& attribute)
{
  this->name_serializer_ = &name;
  this->class__serializer_ = &class_;
  this->position_serializer_ = &position;
  this->rotation_serializer_ = &rotation;
  this->scale_serializer_ = &scale;
  this->attribute_serializer_ = &attribute;
}

node_sskel::
node_sskel ()
: node_impl_ (0),
  name_serializer_ (0),
  class__serializer_ (0),
  position_serializer_ (0),
  rotation_serializer_ (0),
  scale_serializer_ (0),
  attribute_serializer_ (0)
{
}

node_sskel::
node_sskel (node_sskel* impl, void*)
: ::xsde::cxx::serializer::validating::complex_content (impl, 0),
  node_impl_ (impl),
  name_serializer_ (0),
  class__serializer_ (0),
  position_serializer_ (0),
  rotation_serializer_ (0),
  scale_serializer_ (0),
  attribute_serializer_ (0)
{
}

#include <assert.h>

// vec3_type_sskel
//

void vec3_type_sskel::
_reset ()
{
  typedef ::xsde::cxx::serializer::validating::complex_content base;
  base::_reset ();

  if (this->x_serializer_)
    this->x_serializer_->_reset ();

  if (this->y_serializer_)
    this->y_serializer_->_reset ();

  if (this->z_serializer_)
    this->z_serializer_->_reset ();
}

// vec4_type_sskel
//

void vec4_type_sskel::
_reset ()
{
  typedef ::xsde::cxx::serializer::validating::complex_content base;
  base::_reset ();

  if (this->x_serializer_)
    this->x_serializer_->_reset ();

  if (this->y_serializer_)
    this->y_serializer_->_reset ();

  if (this->z_serializer_)
    this->z_serializer_->_reset ();

  if (this->w_serializer_)
    this->w_serializer_->_reset ();
}

// scene_graph_sskel
//

bool scene_graph_sskel::
nodes_present ()
{
  return this->scene_graph_impl_ ? this->scene_graph_impl_->nodes_present () : false;
}

bool scene_graph_sskel::
scenes_present ()
{
  return this->scene_graph_impl_ ? this->scene_graph_impl_->scenes_present () : false;
}

void scene_graph_sskel::
_reset ()
{
  if (this->resetting_)
    return;

  typedef ::xsde::cxx::serializer::validating::complex_content base;
  base::_reset ();

  this->resetting_ = true;

  if (this->nodes_serializer_)
    this->nodes_serializer_->_reset ();

  if (this->scenes_serializer_)
    this->scenes_serializer_->_reset ();

  this->resetting_ = false;
}

// nodes_sskel
//

void nodes_sskel::
_reset ()
{
  if (this->resetting_)
    return;

  typedef ::xsde::cxx::serializer::validating::complex_content base;
  base::_reset ();

  this->resetting_ = true;

  if (this->node_serializer_)
    this->node_serializer_->_reset ();

  this->resetting_ = false;
}

// scene_sskel
//

bool scene_sskel::
graph_present ()
{
  return this->scene_impl_ ? this->scene_impl_->graph_present () : false;
}

void scene_sskel::
_reset ()
{
  typedef ::xsde::cxx::serializer::validating::complex_content base;
  base::_reset ();

  if (this->name_serializer_)
    this->name_serializer_->_reset ();

  if (this->graph_serializer_)
    this->graph_serializer_->_reset ();
}

// scenes_sskel
//

void scenes_sskel::
_reset ()
{
  if (this->resetting_)
    return;

  typedef ::xsde::cxx::serializer::validating::complex_content base;
  base::_reset ();

  this->resetting_ = true;

  if (this->scene_serializer_)
    this->scene_serializer_->_reset ();

  this->resetting_ = false;
}

// attribute_sskel
//

bool attribute_sskel::
name_present ()
{
  return this->attribute_impl_ ? this->attribute_impl_->name_present () : false;
}

bool attribute_sskel::
value_present ()
{
  return this->attribute_impl_ ? this->attribute_impl_->value_present () : false;
}

void attribute_sskel::
_reset ()
{
  typedef ::xsde::cxx::serializer::validating::complex_content base;
  base::_reset ();

  if (this->name_serializer_)
    this->name_serializer_->_reset ();

  if (this->value_serializer_)
    this->value_serializer_->_reset ();
}

// node_sskel
//

bool node_sskel::
position_present ()
{
  return this->node_impl_ ? this->node_impl_->position_present () : false;
}

bool node_sskel::
rotation_present ()
{
  return this->node_impl_ ? this->node_impl_->rotation_present () : false;
}

bool node_sskel::
scale_present ()
{
  return this->node_impl_ ? this->node_impl_->scale_present () : false;
}

bool node_sskel::
attribute_next ()
{
  return this->node_impl_ ? this->node_impl_->attribute_next () : false;
}

void node_sskel::
_reset ()
{
  if (this->resetting_)
    return;

  typedef ::xsde::cxx::serializer::validating::complex_content base;
  base::_reset ();

  if (this->name_serializer_)
    this->name_serializer_->_reset ();

  if (this->class__serializer_)
    this->class__serializer_->_reset ();

  this->resetting_ = true;

  if (this->position_serializer_)
    this->position_serializer_->_reset ();

  if (this->rotation_serializer_)
    this->rotation_serializer_->_reset ();

  if (this->scale_serializer_)
    this->scale_serializer_->_reset ();

  if (this->attribute_serializer_)
    this->attribute_serializer_->_reset ();

  this->resetting_ = false;
}

// Element validation and serialization for scene_graph_sskel.
//
void scene_graph_sskel::
_serialize_content ()
{
  ::xsde::cxx::serializer::context& ctx = this->_context ();

  // nodes
  //
  if (this->nodes_present ())
  {
    const ::nodes& r = this->nodes ();

    if (this->nodes_serializer_)
    {
      this->nodes_serializer_->pre (r);
      this->_start_element ("nodes");
      this->nodes_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->nodes_serializer_->_serialize_attributes ();

      if (ctx.error_type ())
        return;

      this->nodes_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->nodes_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_element ();
      this->nodes_serializer_->post ();
    }
  }

  // scenes
  //
  if (this->scenes_present ())
  {
    const ::scenes& r = this->scenes ();

    if (this->scenes_serializer_)
    {
      this->scenes_serializer_->pre (r);
      this->_start_element ("scenes");
      this->scenes_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->scenes_serializer_->_serialize_attributes ();

      if (ctx.error_type ())
        return;

      this->scenes_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->scenes_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_element ();
      this->scenes_serializer_->post ();
    }
  }
}

// Element validation and serialization for nodes_sskel.
//
void nodes_sskel::
_serialize_content ()
{
  ::xsde::cxx::serializer::context& ctx = this->_context ();

  // node
  //
  {
    size_t i = 0;
    for (; this->node_next (); ++i)
    {
      const ::node& r = this->node ();

      if (this->node_serializer_)
      {
        this->node_serializer_->pre (r);
        this->_start_element ("node");
        this->node_serializer_->_pre_impl (ctx);

        if (ctx.error_type ())
          return;

        this->node_serializer_->_serialize_attributes ();

        if (ctx.error_type ())
          return;

        this->node_serializer_->_serialize_content ();

        if (ctx.error_type ())
          return;

        this->node_serializer_->_post_impl ();

        if (ctx.error_type ())
          return;

        this->_end_element ();
        this->node_serializer_->post ();
      }
      else
      {
        this->_schema_error (::xsde::cxx::schema_error::expected_element);
        return;
      }
    }

    if (i < 1UL)
    {
      this->_schema_error (::xsde::cxx::schema_error::expected_element);
      return;
    }
  }
}

// Element validation and serialization for scenes_sskel.
//
void scenes_sskel::
_serialize_content ()
{
  ::xsde::cxx::serializer::context& ctx = this->_context ();

  // scene
  //
  {
    size_t i = 0;
    for (; this->scene_next (); ++i)
    {
      const ::scene& r = this->scene ();

      if (this->scene_serializer_)
      {
        this->scene_serializer_->pre (r);
        this->_start_element ("scene");
        this->scene_serializer_->_pre_impl (ctx);

        if (ctx.error_type ())
          return;

        this->scene_serializer_->_serialize_attributes ();

        if (ctx.error_type ())
          return;

        this->scene_serializer_->_serialize_content ();

        if (ctx.error_type ())
          return;

        this->scene_serializer_->_post_impl ();

        if (ctx.error_type ())
          return;

        this->_end_element ();
        this->scene_serializer_->post ();
      }
      else
      {
        this->_schema_error (::xsde::cxx::schema_error::expected_element);
        return;
      }
    }

    if (i < 1UL)
    {
      this->_schema_error (::xsde::cxx::schema_error::expected_element);
      return;
    }
  }
}

// Element validation and serialization for node_sskel.
//
void node_sskel::
_serialize_content ()
{
  ::xsde::cxx::serializer::context& ctx = this->_context ();

  // position
  //
  if (this->position_present ())
  {
    const ::vec3_type& r = this->position ();

    if (this->position_serializer_)
    {
      this->position_serializer_->pre (r);
      this->_start_element ("position");
      this->position_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->position_serializer_->_serialize_attributes ();

      if (ctx.error_type ())
        return;

      this->position_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->position_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_element ();
      this->position_serializer_->post ();
    }
  }

  // rotation
  //
  if (this->rotation_present ())
  {
    const ::vec4_type& r = this->rotation ();

    if (this->rotation_serializer_)
    {
      this->rotation_serializer_->pre (r);
      this->_start_element ("rotation");
      this->rotation_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->rotation_serializer_->_serialize_attributes ();

      if (ctx.error_type ())
        return;

      this->rotation_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->rotation_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_element ();
      this->rotation_serializer_->post ();
    }
  }

  // scale
  //
  if (this->scale_present ())
  {
    const ::vec3_type& r = this->scale ();

    if (this->scale_serializer_)
    {
      this->scale_serializer_->pre (r);
      this->_start_element ("scale");
      this->scale_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->scale_serializer_->_serialize_attributes ();

      if (ctx.error_type ())
        return;

      this->scale_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->scale_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_element ();
      this->scale_serializer_->post ();
    }
  }

  // attribute
  //
  while (this->attribute_next ())
  {
    const ::attribute& r = this->attribute ();

    if (this->attribute_serializer_)
    {
      this->attribute_serializer_->pre (r);
      this->_start_element ("attribute");
      this->attribute_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->attribute_serializer_->_serialize_attributes ();

      if (ctx.error_type ())
        return;

      this->attribute_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->attribute_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_element ();
      this->attribute_serializer_->post ();
    }
  }
}

// Attribute validation and serialization for vec3_type_sskel.
//
void vec3_type_sskel::
_serialize_attributes ()
{
  ::xsde::cxx::serializer::context& ctx = this->_context ();

  // x
  //
  {
    float r = this->x ();

    if (this->x_serializer_)
    {
      this->x_serializer_->pre (r);
      this->_start_attribute ("x");
      this->x_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->x_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->x_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->x_serializer_->post ();
    }
    else
    {
      this->_schema_error (::xsde::cxx::schema_error::expected_attribute);
      return;
    }
  }

  // y
  //
  {
    float r = this->y ();

    if (this->y_serializer_)
    {
      this->y_serializer_->pre (r);
      this->_start_attribute ("y");
      this->y_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->y_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->y_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->y_serializer_->post ();
    }
    else
    {
      this->_schema_error (::xsde::cxx::schema_error::expected_attribute);
      return;
    }
  }

  // z
  //
  {
    float r = this->z ();

    if (this->z_serializer_)
    {
      this->z_serializer_->pre (r);
      this->_start_attribute ("z");
      this->z_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->z_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->z_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->z_serializer_->post ();
    }
    else
    {
      this->_schema_error (::xsde::cxx::schema_error::expected_attribute);
      return;
    }
  }
}

// Attribute validation and serialization for vec4_type_sskel.
//
void vec4_type_sskel::
_serialize_attributes ()
{
  ::xsde::cxx::serializer::context& ctx = this->_context ();

  // x
  //
  {
    float r = this->x ();

    if (this->x_serializer_)
    {
      this->x_serializer_->pre (r);
      this->_start_attribute ("x");
      this->x_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->x_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->x_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->x_serializer_->post ();
    }
    else
    {
      this->_schema_error (::xsde::cxx::schema_error::expected_attribute);
      return;
    }
  }

  // y
  //
  {
    float r = this->y ();

    if (this->y_serializer_)
    {
      this->y_serializer_->pre (r);
      this->_start_attribute ("y");
      this->y_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->y_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->y_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->y_serializer_->post ();
    }
    else
    {
      this->_schema_error (::xsde::cxx::schema_error::expected_attribute);
      return;
    }
  }

  // z
  //
  {
    float r = this->z ();

    if (this->z_serializer_)
    {
      this->z_serializer_->pre (r);
      this->_start_attribute ("z");
      this->z_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->z_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->z_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->z_serializer_->post ();
    }
    else
    {
      this->_schema_error (::xsde::cxx::schema_error::expected_attribute);
      return;
    }
  }

  // w
  //
  {
    float r = this->w ();

    if (this->w_serializer_)
    {
      this->w_serializer_->pre (r);
      this->_start_attribute ("w");
      this->w_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->w_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->w_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->w_serializer_->post ();
    }
    else
    {
      this->_schema_error (::xsde::cxx::schema_error::expected_attribute);
      return;
    }
  }
}

// Attribute validation and serialization for scene_sskel.
//
void scene_sskel::
_serialize_attributes ()
{
  ::xsde::cxx::serializer::context& ctx = this->_context ();

  // name
  //
  {
    const ::std::string& r = this->name ();

    if (this->name_serializer_)
    {
      this->name_serializer_->pre (r);
      this->_start_attribute ("name");
      this->name_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->name_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->name_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->name_serializer_->post ();
    }
    else
    {
      this->_schema_error (::xsde::cxx::schema_error::expected_attribute);
      return;
    }
  }

  // graph
  //
  if (this->graph_present ())
  {
    const ::std::string& r = this->graph ();

    if (this->graph_serializer_)
    {
      this->graph_serializer_->pre (r);
      this->_start_attribute ("graph");
      this->graph_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->graph_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->graph_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->graph_serializer_->post ();
    }
  }
}

// Attribute validation and serialization for attribute_sskel.
//
void attribute_sskel::
_serialize_attributes ()
{
  ::xsde::cxx::serializer::context& ctx = this->_context ();

  // name
  //
  if (this->name_present ())
  {
    const ::std::string& r = this->name ();

    if (this->name_serializer_)
    {
      this->name_serializer_->pre (r);
      this->_start_attribute ("name");
      this->name_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->name_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->name_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->name_serializer_->post ();
    }
  }

  // value
  //
  if (this->value_present ())
  {
    const ::std::string& r = this->value ();

    if (this->value_serializer_)
    {
      this->value_serializer_->pre (r);
      this->_start_attribute ("value");
      this->value_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->value_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->value_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->value_serializer_->post ();
    }
  }
}

// Attribute validation and serialization for node_sskel.
//
void node_sskel::
_serialize_attributes ()
{
  ::xsde::cxx::serializer::context& ctx = this->_context ();

  // name
  //
  {
    const ::std::string& r = this->name ();

    if (this->name_serializer_)
    {
      this->name_serializer_->pre (r);
      this->_start_attribute ("name");
      this->name_serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->name_serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->name_serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->name_serializer_->post ();
    }
    else
    {
      this->_schema_error (::xsde::cxx::schema_error::expected_attribute);
      return;
    }
  }

  // class_
  //
  {
    const ::std::string& r = this->class_ ();

    if (this->class__serializer_)
    {
      this->class__serializer_->pre (r);
      this->_start_attribute ("class");
      this->class__serializer_->_pre_impl (ctx);

      if (ctx.error_type ())
        return;

      this->class__serializer_->_serialize_content ();

      if (ctx.error_type ())
        return;

      this->class__serializer_->_post_impl ();

      if (ctx.error_type ())
        return;

      this->_end_attribute ();
      this->class__serializer_->post ();
    }
    else
    {
      this->_schema_error (::xsde::cxx::schema_error::expected_attribute);
      return;
    }
  }
}

// Begin epilogue.
//
//
// End epilogue.

