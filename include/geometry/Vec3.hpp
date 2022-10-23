#ifndef VEC3_HPP
#define VEC3_HPP

#include <array>
#include <cmath>
#include <iostream>
#include <type_traits>

namespace Utils
{

template <typename T>
class Vec3
{
public:
	Vec3(std::array<T, 3> values) : v(values) {}
	Vec3(const T x, const T y, const T z) : v({x, y, z}) {}

	using const_reference = T const&;
	using reference = T&;
	using value_type = T;

	Vec3(const Vec3&) = default;
	Vec3(Vec3&&) = default;
	Vec3& operator=(const Vec3&) = default;
	Vec3& operator=(Vec3&&) = default;

	reference at(const int index)
	{
		if (index >= 0 && index <= 3)
		{
			return v.at(index);
		}
		else
		{
			throw std::out_of_range("Invalid index for array size 3");
		}
	}

	const_reference at(const int index) const
	{
		if (index >= 0 && index <= 3)
		{
			return v.at(index);
		}
		else
		{
			throw std::out_of_range("Invalid index for array size 3");
		}
	}

	inline const_reference x() const { return v.at(0); }
	inline const_reference y() const { return v.at(1); }
	inline const_reference z() const { return v.at(2); }

	inline const_reference a() const { return v.at(0); }
	inline const_reference b() const { return v.at(1); }
	inline const_reference c() const { return v.at(2); }

	Vec3 unitVector() const noexcept { return *this / length(); }

	double length() const noexcept { return std::sqrt(length_squared()); }

	double length_squared() const noexcept
	{
		return ((v.at(0) * v.at(0)) + (v.at(1) * v.at(1)) + (v.at(2) * v.at(2)));
	}

	double dot(const Vec3& rhs) const noexcept
	{
		return {v.at(0) * rhs.v.at(0) + v.at(1) * rhs.v.at(1) + v.at(2) * rhs.v.at(2)};
	}

	static double dot(const Vec3& lhs, const Vec3& rhs)
	{
		return {lhs.at(0) * rhs.v.at(0) + lhs.at(1) * rhs.v.at(1) + lhs.at(2) * rhs.v.at(2)};
	}

	Vec3 cross(const Vec3& rhs) const noexcept
	{
		return {v.at(1) * rhs.at(2) - v.at(2) * rhs.at(1),
				v.at(2) * rhs.at(0) - v.at(0) * rhs.at(2),
				v.at(0) * rhs.at(1) - v.at(1) * rhs.at(0)};
	}

	static Vec3 cross(const Vec3& lhs, const Vec3& rhs)
	{
		return {lhs.at(1) * rhs.at(2) - lhs.at(2) * rhs.at(1),
				lhs.at(2) * rhs.at(0) - lhs.at(0) * rhs.at(2),
				lhs.at(0) * rhs.at(1) - lhs.at(1) * rhs.at(0)};
	}

	Vec3& operator*=(const Vec3& rhs) noexcept
	{
		v.at(0) *= rhs.v.at(0);
		v.at(1) *= rhs.v.at(1);
		v.at(2) *= rhs.v.at(2);

		return *this;
	}

	Vec3& operator+=(const Vec3& rhs)
	{
		v.at(0) += rhs.v.at(0);
		v.at(1) += rhs.v.at(1);
		v.at(2) += rhs.v.at(2);

		return *this;
	}

	Vec3& operator-=(const Vec3& rhs)
	{
		v.at(0) -= rhs.v.at(0);
		v.at(1) -= rhs.v.at(1);
		v.at(2) -= rhs.v.at(2);

		return *this;
	}

	Vec3& operator/=(const double value)
	{
		if (value == 0)
		{
			throw std::runtime_error("Division by 0");
		}

		v.at(0) /= value;
		v.at(1) /= value;
		v.at(2) /= value;

		return *this;
	}

	Vec3& operator*=(const double value)
	{
		v.at(0) *= value;
		v.at(1) *= value;
		v.at(2) *= value;

		return *this;
	}

	Vec3 operator+(const Vec3& rhs)
	{
		return {v.at(0) + rhs.v.at(0), v.at(1) + rhs.v.at(1), v.at(2) + rhs.v.at(2)};
	}

private:
	std::array<T, 3> v;
};

template <typename T,
		  typename std::enable_if_t<!std::is_integral<typename T::value_type>::value>* = nullptr>
Vec3<int> getIntegralVector(const T& vec)
{
	return {static_cast<int>(vec.x()), static_cast<int>(vec.y()), static_cast<int>(vec.z())};
}

template <typename T>
inline bool operator==(const Vec3<T>& lhs, const Vec3<T>& rhs)
{
	return lhs.x() == rhs.x() && lhs.y() == rhs.y() && lhs.z() == rhs.z();
}

template <typename T>
inline std::ostream& operator<<(std::ostream& out, const Vec3<T>& vec)
{
	return out << vec.x() << ' ' << vec.y() << ' ' << vec.z();
}

template <typename T>
inline Vec3<T> operator*(const Vec3<T>& vec, const double value)
{
	return {vec.x() * value, vec.y() * value, vec.z() * value};
}

template <typename T>
inline Vec3<T> operator*(const double value, const Vec3<T>& vec)
{
	return vec * value;
}

template <typename T>
inline Vec3<T> operator/(const Vec3<T>& vec, const double value)
{
	return {vec.x() / value, vec.y() / value, vec.z() / value};
}

template <typename T>
inline Vec3<T> operator/(const double value, const Vec3<T>& vec)
{
	return vec * value;
}

template <typename T>
inline Vec3<T> operator+(const Vec3<T>& lhs, const Vec3<T>& rhs)
{
	return {lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z()};
}

template <typename T>
Vec3<T> operator-(const Vec3<T>& lhs, const Vec3<T>& rhs)
{
	return {lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z()};
}

template <typename T>
Vec3<T> operator*(const Vec3<T>& lhs, const Vec3<T>& rhs)
{
	return {lhs.x() * rhs.x(), lhs.y() * rhs.y(), lhs.z() * rhs.z()};
}

template <typename T>
Vec3<T> operator/(const Vec3<T>& lhs, const Vec3<T>& rhs)
{
	return {lhs.x() / rhs.x(), lhs.y() / rhs.y(), lhs.z() / rhs.z()};
}

template <typename T>
Vec3<T> operator-(const Vec3<T>& vec)
{
	return { -vec.x(), -vec.y(), -vec.z() };
}

}  // namespace Utils

template <typename T>
using Vec3 = Utils::Vec3<T>;
using Vec3d = Utils::Vec3<double>;
using Point3d = Utils::Vec3<double>;
using Color3d = Utils::Vec3<double>;

#endif	// VEC3_HPP