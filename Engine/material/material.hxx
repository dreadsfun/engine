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

#ifndef E__VS14PRJBKP_ENGINE_MATERIAL_MATERIAL_HXX
#define E__VS14PRJBKP_ENGINE_MATERIAL_MATERIAL_HXX

#include <xsde/cxx/version.hxx>

#if (XSDE_INT_VERSION != 3020000L)
#error XSD/e runtime version mismatch
#endif

#include <xsde/cxx/config.hxx>

#ifndef XSDE_ENCODING_UTF8
#error the generated code uses the UTF-8 encodingwhile the XSD/e runtime does not (reconfigure the runtime or change the --char-encoding value)
#endif

#ifndef XSDE_STL
#error the generated code uses STL while the XSD/e runtime does not (reconfigure the runtime or add --no-stl)
#endif

#ifndef XSDE_EXCEPTIONS
#error the generated code uses exceptions while the XSD/e runtime does not (reconfigure the runtime or add --no-exceptions)
#endif

#ifndef XSDE_LONGLONG
#error the generated code uses long long while the XSD/e runtime does not (reconfigure the runtime or add --no-long-long)
#endif

#ifdef XSDE_CUSTOM_ALLOCATOR
#error the XSD/e runtime uses custom allocator while the generated code does not (reconfigure the runtime or add --custom-allocator)
#endif

#include <xsde/cxx/pre.hxx>

// Begin prologue.
//
//
// End prologue.

#include <string>
#include <xsde/cxx/hybrid/xml-schema.hxx>
#include <xsde/cxx/hybrid/sequence.hxx>

namespace xml_schema
{
  using ::xsde::cxx::hybrid::any_type;
  typedef ::std::string any_simple_type;

  typedef signed char byte;
  using ::xsde::cxx::hybrid::byte_base;

  typedef unsigned char unsigned_byte;
  using ::xsde::cxx::hybrid::unsigned_byte_base;

  typedef short short_;
  using ::xsde::cxx::hybrid::short_base;

  typedef unsigned short unsigned_short;
  using ::xsde::cxx::hybrid::unsigned_short_base;

  typedef int int_;
  using ::xsde::cxx::hybrid::int_base;

  typedef unsigned int unsigned_int;
  using ::xsde::cxx::hybrid::unsigned_int_base;

  typedef long long long_;
  using ::xsde::cxx::hybrid::long_base;

  typedef unsigned long long unsigned_long;
  using ::xsde::cxx::hybrid::unsigned_long_base;

  typedef long integer;
  using ::xsde::cxx::hybrid::integer_base;

  typedef long non_positive_integer;
  using ::xsde::cxx::hybrid::non_positive_integer_base;

  typedef unsigned long non_negative_integer;
  using ::xsde::cxx::hybrid::non_negative_integer_base;

  typedef unsigned long positive_integer;
  using ::xsde::cxx::hybrid::positive_integer_base;

  typedef long negative_integer;
  using ::xsde::cxx::hybrid::negative_integer_base;

  typedef bool boolean;
  using ::xsde::cxx::hybrid::boolean_base;

  typedef float float_;
  using ::xsde::cxx::hybrid::float_base;

  typedef double double_;
  using ::xsde::cxx::hybrid::double_base;

  typedef double decimal;
  using ::xsde::cxx::hybrid::decimal_base;

  typedef ::std::string string;

  typedef ::std::string normalized_string;

  typedef ::std::string token;

  typedef ::std::string name;

  typedef ::std::string nmtoken;

  typedef ::xsde::cxx::string_sequence nmtokens;

  typedef ::std::string ncname;

  typedef ::std::string language;

  typedef ::std::string id;

  typedef ::std::string idref;

  typedef ::xsde::cxx::string_sequence idrefs;

  typedef ::std::string uri;

  using ::xsde::cxx::qname;

  using ::xsde::cxx::buffer;
  typedef ::xsde::cxx::buffer base64_binary;
  typedef ::xsde::cxx::buffer hex_binary;

  using ::xsde::cxx::time_zone;
  using ::xsde::cxx::date;
  using ::xsde::cxx::date_time;
  using ::xsde::cxx::duration;
  using ::xsde::cxx::gday;
  using ::xsde::cxx::gmonth;
  using ::xsde::cxx::gmonth_day;
  using ::xsde::cxx::gyear;
  using ::xsde::cxx::gyear_month;
  using ::xsde::cxx::time;

  using ::xsde::cxx::hybrid::pod_sequence;
  using ::xsde::cxx::hybrid::fix_sequence;
  using ::xsde::cxx::hybrid::var_sequence;
  using ::xsde::cxx::string_sequence;
  using ::xsde::cxx::hybrid::data_sequence;
}

class materials;
class vector;
class shader;
class texture;
class material;

// materials (variable-length)
//
class materials
{
  private:
  materials (const materials&);
  materials& operator= (const materials&);

  public:
  materials ();

  ~materials ();

  // material
  //
  typedef ::xsde::cxx::hybrid::var_sequence< ::material > material_sequence;
  typedef material_sequence::iterator material_iterator;
  typedef material_sequence::const_iterator material_const_iterator;

  const material_sequence&
  material () const;

  material_sequence&
  material ();

  private:
  material_sequence material_;
};

// vector (fixed-length)
//
class vector
{
  public:
  vector ();

  vector (const vector&);
  vector& operator= (const vector&);

  ~vector ();

  // uniform
  //
  const ::std::string&
  uniform () const;

  ::std::string&
  uniform ();

  void
  uniform (const ::std::string&);

  // x
  //
  float
  x () const;

  float&
  x ();

  void
  x (float);

  // y
  //
  bool
  y_present () const;

  void
  y_present (bool);

  float
  y () const;

  float&
  y ();

  void
  y (float);

  // z
  //
  bool
  z_present () const;

  void
  z_present (bool);

  float
  z () const;

  float&
  z ();

  void
  z (float);

  // w
  //
  bool
  w_present () const;

  void
  w_present (bool);

  float
  w () const;

  float&
  w ();

  void
  w (float);

  private:
  ::std::string uniform_;
  float x_;
  float y_;
  unsigned char y_present_;
  float z_;
  unsigned char z_present_;
  float w_;
  unsigned char w_present_;
};

// shader (fixed-length)
//
class shader
{
  public:
  shader ();

  shader (const shader&);
  shader& operator= (const shader&);

  ~shader ();

  // file
  //
  const ::std::string&
  file () const;

  ::std::string&
  file ();

  void
  file (const ::std::string&);

  private:
  ::std::string file_;
};

// texture (fixed-length)
//
class texture
{
  public:
  texture ();

  texture (const texture&);
  texture& operator= (const texture&);

  ~texture ();

  // sampler
  //
  const ::std::string&
  sampler () const;

  ::std::string&
  sampler ();

  void
  sampler (const ::std::string&);

  // file
  //
  const ::std::string&
  file () const;

  ::std::string&
  file ();

  void
  file (const ::std::string&);

  private:
  ::std::string sampler_;
  ::std::string file_;
};

// material (variable-length)
//
class material
{
  private:
  material (const material&);
  material& operator= (const material&);

  public:
  material ();

  ~material ();

  // name
  //
  const ::std::string&
  name () const;

  ::std::string&
  name ();

  void
  name (const ::std::string&);

  // shader
  //
  const ::shader&
  shader () const;

  ::shader&
  shader ();

  void
  shader (const ::shader&);

  // texture
  //
  typedef ::xsde::cxx::hybrid::fix_sequence< ::texture > texture_sequence;
  typedef texture_sequence::iterator texture_iterator;
  typedef texture_sequence::const_iterator texture_const_iterator;

  const texture_sequence&
  texture () const;

  texture_sequence&
  texture ();

  // vector
  //
  typedef ::xsde::cxx::hybrid::fix_sequence< ::vector > vector_sequence;
  typedef vector_sequence::iterator vector_iterator;
  typedef vector_sequence::const_iterator vector_const_iterator;

  const vector_sequence&
  vector () const;

  vector_sequence&
  vector ();

  private:
  ::std::string name_;
  ::shader shader_;
  texture_sequence texture_;
  vector_sequence vector_;
};

// Begin epilogue.
//
//
// End epilogue.

#include <xsde/cxx/post.hxx>

#endif // E__VS14PRJBKP_ENGINE_MATERIAL_MATERIAL_HXX
