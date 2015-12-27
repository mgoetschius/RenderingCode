///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Mathematics (glm.g-truc.net)
///
/// Copyright (c) 2005 - 2014 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core	
/// @file glm/core/type_mat2x2.hpp
/// @date 2005-01-27 / 2011-06-15
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "../fwd.hpp"
#include "type_vec2.hpp"
#include "type_mat.hpp"
#include <limits>
#if GLM_HAS_INITIALIZER_LISTS
#	include <initializer_list>
#endif
#if GLM_HAS_RVALUE_REFERENCES
#	include <algorithm>
#endif
#include <limits>
#include <cstddef>

namespace glm{
namespace detail
{
	template <typename T, precision P>
	struct tmat2x2
	{
		enum ctor{_null};
		typedef T value_type;
		typedef std::size_t size_type;
		typedef tvec2<T, P> col_type;
		typedef tvec2<T, P> row_type;
		typedef tmat2x2<T, P> type;
		typedef tmat2x2<T, P> transpose_type;

		GLM_FUNC_DECL GLM_CONSTEXPR length_t length() const;

		template <typename U, precision Q>
		friend tvec2<U, Q> operator/(tmat2x2<U, Q> const & m, tvec2<U, Q> const & v);
		template <typename U, precision Q>
		friend tvec2<U, Q> operator/(tvec2<U, Q> const & v, tmat2x2<U, Q> const & m);

	private:
		/// @cond DETAIL
		col_type value[2];
		/// @endcond
		
	public:
		//////////////////////////////////////
		// Constructors
		GLM_FUNC_DECL tmat2x2();
		GLM_FUNC_DECL tmat2x2(tmat2x2<T, P> const & m);
		template <precision Q>
		GLM_FUNC_DECL tmat2x2(tmat2x2<T, Q> const & m);

		GLM_FUNC_DECL explicit tmat2x2(
			ctor Null);
		GLM_FUNC_DECL explicit tmat2x2(
			T const & x);
		GLM_FUNC_DECL tmat2x2(
			T const & x1, T const & y1,
			T const & x2, T const & y2);
		GLM_FUNC_DECL tmat2x2(
			col_type const & v1,
			col_type const & v2);

		//////////////////////////////////////
		// Conversions
		template <typename U, typename V, typename M, typename N>
		GLM_FUNC_DECL tmat2x2(
			U const & x1, V const & y1,
			M const & x2, N const & y2);

		template <typename U, typename V>
		GLM_FUNC_DECL tmat2x2(
			tvec2<U, P> const & v1,
			tvec2<V, P> const & v2);

		//////////////////////////////////////
		// Matrix conversions
		template <typename U, precision Q>
		GLM_FUNC_DECL explicit tmat2x2(tmat2x2<U, Q> const & m);

		GLM_FUNC_DECL explicit tmat2x2(tmat3x3<T, P> const & x);
		GLM_FUNC_DECL explicit tmat2x2(tmat4x4<T, P> const & x);
		GLM_FUNC_DECL explicit tmat2x2(tmat2x3<T, P> const & x);
		GLM_FUNC_DECL explicit tmat2x2(tmat3x2<T, P> const & x);
		GLM_FUNC_DECL explicit tmat2x2(tmat2x4<T, P> const & x);
		GLM_FUNC_DECL explicit tmat2x2(tmat4x2<T, P> const & x);
		GLM_FUNC_DECL explicit tmat2x2(tmat3x4<T, P> const & x);
		GLM_FUNC_DECL explicit tmat2x2(tmat4x3<T, P> const & x);

		//////////////////////////////////////
		// Accesses

		GLM_FUNC_DECL col_type & operator[](length_t i);
		GLM_FUNC_DECL col_type const & operator[](length_t i) const;

		// Unary updatable operators
#		if(GLM_HAS_DEFAULTED_FUNCTIONS && GLM_HAS_RVALUE_REFERENCES)
			GLM_FUNC_DECL tmat2x2<T, P> & operator=(tmat2x2<T, P> && m)
			{
				this->value[0] = std::move(m.value[0]);
				this->value[1] = std::move(m.value[1]);
				return *this;
			}
#		endif//(GLM_HAS_DEFAULTED_FUNCTIONS && GLM_HAS_RVALUE_REFERENCES)

		GLM_FUNC_DECL tmat2x2<T, P> & operator=(tmat2x2<T, P> const & m);
		template <typename U> 
		GLM_FUNC_DECL tmat2x2<T, P> & operator=(tmat2x2<U, P> const & m);
		template <typename U> 
		GLM_FUNC_DECL tmat2x2<T, P> & operator+=(U s);
		template <typename U> 
		GLM_FUNC_DECL tmat2x2<T, P> & operator+=(tmat2x2<U, P> const & m);
		template <typename U> 
		GLM_FUNC_DECL tmat2x2<T, P> & operator-=(U s);
		template <typename U> 
		GLM_FUNC_DECL tmat2x2<T, P> & operator-=(tmat2x2<U, P> const & m);
		template <typename U> 
		GLM_FUNC_DECL tmat2x2<T, P> & operator*=(U s);
		template <typename U> 
		GLM_FUNC_DECL tmat2x2<T, P> & operator*=(tmat2x2<U, P> const & m);
		template <typename U> 
		GLM_FUNC_DECL tmat2x2<T, P> & operator/=(U s);
		template <typename U> 
		GLM_FUNC_DECL tmat2x2<T, P> & operator/=(tmat2x2<U, P> const & m);

		//////////////////////////////////////
		// Increment and decrement operators

		GLM_FUNC_DECL tmat2x2<T, P> & operator++ ();
		GLM_FUNC_DECL tmat2x2<T, P> & operator-- ();
		GLM_FUNC_DECL tmat2x2<T, P> operator++(int);
		GLM_FUNC_DECL tmat2x2<T, P> operator--(int);
	};

	// Binary operators
	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> operator+ (
		tmat2x2<T, P> const & m,
		T const & s);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> operator+ (
		T const & s,
		tmat2x2<T, P> const & m);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> operator+ (
		tmat2x2<T, P> const & m1,
		tmat2x2<T, P> const & m2);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> operator- (
		tmat2x2<T, P> const & m,
		T const & s);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> operator- (
		T const & s,
		tmat2x2<T, P> const & m);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> operator- (
		tmat2x2<T, P> const & m1,
		tmat2x2<T, P> const & m2);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> operator* (
		tmat2x2<T, P> const & m,
		T const & s);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> operator* (
		T const & s, 
		tmat2x2<T, P> const & m);

	template <typename T, precision P>
	GLM_FUNC_DECL typename tmat2x2<T, P>::col_type operator* (
		tmat2x2<T, P> const & m,
		typename tmat2x2<T, P>::row_type const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL typename tmat2x2<T, P>::row_type operator* (
		typename tmat2x2<T, P>::col_type const & v,
		tmat2x2<T, P> const & m);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> operator* (
		tmat2x2<T, P> const & m1,
		tmat2x2<T, P> const & m2);
		
	template <typename T, precision P>
	GLM_FUNC_DECL tmat3x2<T, P> operator* (
		tmat2x2<T, P> const & m1,
		tmat3x2<T, P> const & m2);
		
	template <typename T, precision P>
	GLM_FUNC_DECL tmat4x2<T, P> operator* (
		tmat2x2<T, P> const & m1,
		tmat4x2<T, P> const & m2);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> operator/ (
		tmat2x2<T, P> const & m,
		T const & s);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> operator/ (
		T const & s,
		tmat2x2<T, P> const & m);

	template <typename T, precision P>
	GLM_FUNC_DECL typename tmat2x2<T, P>::col_type operator/ (
		tmat2x2<T, P> const & m,
		typename tmat2x2<T, P>::row_type const & v);

	template <typename T, precision P>
	GLM_FUNC_DECL typename tmat2x2<T, P>::row_type operator/ (
		typename tmat2x2<T, P>::col_type const & v,
		tmat2x2<T, P> const & m);

	template <typename T, precision P>
	GLM_FUNC_DECL tmat2x2<T, P> operator/ (
		tmat2x2<T, P> const & m1,
		tmat2x2<T, P> const & m2);

	// Unary constant operators
	template <typename T, precision P> 
	GLM_FUNC_DECL tmat2x2<T, P> const operator-(
		tmat2x2<T, P> const & m);
} //namespace detail
} //namespace glm

#ifndef GLM_EXTERNAL_TEMPLATE
#include "type_mat2x2.inl"
#endif
