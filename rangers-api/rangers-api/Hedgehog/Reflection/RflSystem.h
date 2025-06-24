#pragma once
#include <ucsl/rfl/rflclass.h>

namespace hh::fnd {
    UCSL_NEWTYPE_SIMPLE(RflCustomAttribute, ucsl::rfl::rangers::RflCustomAttribute);
    UCSL_NEWTYPE_SIMPLE(RflCustomAttributes, ucsl::rfl::rangers::RflCustomAttributes);
    UCSL_NEWTYPE_SIMPLE(RflClassEnumMember, ucsl::rfl::rangers::RflClassEnumMember);
    UCSL_NEWTYPE_SIMPLE(RflClassEnum, ucsl::rfl::rangers::RflClassEnum);
    UCSL_NEWTYPE_SIMPLE(RflClassMember, ucsl::rfl::rangers::RflClassMember);
    UCSL_NEWTYPE_SIMPLE(RflClass, ucsl::rfl::rangers::RflClass);
}
