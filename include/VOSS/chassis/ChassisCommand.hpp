#pragma once

#include <variant>

namespace voss::chassis {

struct Stop {};
struct Voltages {
	double left;
	double right;
};
struct Chained {
    double left;
    double right;
};

using ChassisCommand = std::variant<Stop, Voltages, Chained>;

template <class... Ts> struct overload : Ts... {
	using Ts::operator()...;
};
template <class... Ts> overload(Ts...) -> overload<Ts...>;

} // namespace voss::chassis