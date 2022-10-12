#ifndef VEC3_HPP
#define VEC3_HPP

#include <array>

namespace Utils
{

template <typename T>
class Vec3
{
public:
    Vec3(std::array<T, 3> values) : v(values) {}
	Vec3(const T x, const T y, const T z) : v({x, y, z}) {}

	using const_reference = const T&;
	using reference = T&;

	Vec3(const Vec3&) = default;
	Vec3(Vec3&&) = default;
	Vec3& operator=(Vec3&) = default;
	Vec3& operator=(Vec3&&) = default;

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

	const_reference x() const { return v.at(0); }
	const_reference y() const { return v.at(1); }
	const_reference z() const { return v.at(2); }

	Vec3& operator*=(const Vec3& rhs)
	{
		v.at(0) *= rhs.v.at(0);
		v.at(1) *= rhs.v.at(1);
		v.at(2) *= rhs.v.at(2);

		return *this;
	}

	Vec3& operator/=(const Vec3& rhs)
	{
		v.at(0) /= rhs.v.at(0);
		v.at(1) /= rhs.v.at(1);
		v.at(2) /= rhs.v.at(2);

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

    Vec3 operator+(const Vec3& rhs)
    {
        return { v.at(0) + rhs.v.at(0), v.at(1) + rhs.v.at(1), v.at(2) + rhs.v.at(2) };
    }

    Vec3 operator-(const Vec3& rhs)
    {
        return { v.at(0) - rhs.v.at(0), v.at(1) - rhs.v.at(1), v.at(2) - rhs.v.at(2) };
    }

    Vec3 operator*(const Vec3& rhs)
    {
        return { v.at(0) * rhs.v.at(0), v.at(1) * rhs.v.at(1), v.at(2) * rhs.v.at(2) };
    }

    Vec3 operator/(const Vec3& rhs)
    {
        return { v.at(0) / rhs.v.at(0), v.at(1) / rhs.v.at(1), v.at(2) / rhs.v.at(2) };
    }

private:
	std::array<T, 3> v;
};


}  // namespace Utility

template <typename T>
inline std::ostream& operator<<(std::ostream& out, const Utils::Vec3<T>& vec)
{
    return out << vec.x() << ' ' << vec.y() << ' ' << vec.z();
}

#endif	// VEC3_HPP