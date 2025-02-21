/*
 * Copyright 2021 Intel Corporation.
 *
 * This software and the related documents are Intel copyrighted materials,
 * and your use of them is governed by the express license under which they
 * were provided to you ("License"). Unless the License provides otherwise,
 * you may not use, modify, copy, publish, distribute, disclose or transmit
 * this software or the related documents without Intel's prior written
 * permission.
 *
 * This software and the related documents are provided as is, with no
 * express or implied warranties, other than those that are expressly
 * stated in the License.
 *
 */

#ifndef DML_COMMON_OPTION_TYPES_HPP
#define DML_COMMON_OPTION_TYPES_HPP

#include "types.hpp"
#include "values.hpp"

#include <cstdint>
#include <type_traits>

namespace dml::ml
{
    /**
     * @todo
     */
    template <typename underlying_type_t>
    class options_interface
    {
    public:
        /**
         * @todo
         */
        explicit constexpr options_interface(underlying_type_t flags = 0u) noexcept: flags_(flags)
        {
        }

        /**
         * @todo
         */
        constexpr explicit operator underlying_type_t() const noexcept
        {
            return flags_;
        }

        /**
         * @todo
         */
        constexpr bool operator==(const options_interface &rhs) const
        {
            return flags_ == rhs.flags_;
        }

        /**
         * @todo
         */
        constexpr bool operator!=(const options_interface &rhs) const
        {
            return rhs != *this;
        }

        /**
         * @todo
         */
        [[nodiscard]] constexpr bool contains(const options_interface &rhs) const noexcept
        {
            return (this->flags_ & rhs.flags_) == rhs.flags_;
        }

        /**
         * @todo
         */

    protected:
        underlying_type_t flags_; /**< @todo */
    };

    /**
     * @todo
     */
    class options: public options_interface<flags_t>
    {
    public:
        using options_interface<flags_t>::options_interface;

        constexpr options(flag value): options_interface<flags_t>(static_cast<std::underlying_type_t<flag>>(value))
        {
        }
    };

    /**
     * @todo
     */
    class mem_move_options: public options
    {
    public:
        using options::options;

        /**
         * @todo
         */
        constexpr mem_move_options operator|(const mem_move_options &rhs) const noexcept
        {
            return mem_move_options(this->flags_ | rhs.flags_);
        }
    };

    /**
 * @todo
 */
    class fill_options: public options
    {
    public:
        using options::options;

        /**
         * @todo
         */
        constexpr fill_options operator|(const fill_options &rhs) const noexcept
        {
            return fill_options(this->flags_ | rhs.flags_);
        }
    };

    /**
* @todo
*/
    class dualcast_options: public options
    {
    public:
        using options::options;

        /**
         * @todo
         */
        constexpr dualcast_options operator|(const dualcast_options &rhs) const noexcept
        {
            return dualcast_options(this->flags_ | rhs.flags_);
        }
    };

    /**
* @todo
*/
    class compare_options: public options
    {
    public:
        using options::options;

        /**
         * @todo
         */
        constexpr compare_options operator|(const compare_options &rhs) const noexcept
        {
            return compare_options(this->flags_ | rhs.flags_);
        }
    };

    /**
 * @todo
 */
    class compare_pattern_options: public options
    {
    public:
        using options::options;

        /**
         * @todo
         */
        constexpr compare_pattern_options operator|(const compare_pattern_options &rhs) const noexcept
        {
            return compare_pattern_options(this->flags_ | rhs.flags_);
        }
    };

    /**
* @todo
*/
    class crc_options: public options
    {
    public:
        using options::options;

        /**
         * @todo
         */
        constexpr crc_options operator|(const crc_options &rhs) const noexcept
        {
            return crc_options(this->flags_ | rhs.flags_);
        }
    };

    /**
* @todo
*/
    class copy_crc_options: public options
    {
    public:
        using options::options;

        /**
         * @todo
         */
        constexpr copy_crc_options operator|(const copy_crc_options &rhs) const noexcept
        {
            return copy_crc_options(this->flags_ | rhs.flags_);
        }
    };

    /**
* @todo
*/
    class create_delta_options: public options
    {
    public:
        using options::options;

        /**
         * @todo
         */
        constexpr create_delta_options operator|(const create_delta_options &rhs) const noexcept
        {
            return create_delta_options(this->flags_ | rhs.flags_);
        }
    };

    /**
* @todo
*/
    class apply_delta_options: public options
    {
    public:
        using options::options;

        /**
         * @todo
         */
        constexpr apply_delta_options operator|(const apply_delta_options &rhs) const noexcept
        {
            return apply_delta_options(this->flags_ | rhs.flags_);
        }
    };

    /**
* @todo
*/
    class cache_flush_options: public options
    {
    public:
        using options::options;

        /**
         * @todo
         */
        constexpr cache_flush_options operator|(const cache_flush_options &rhs) const noexcept
        {
            return cache_flush_options(this->flags_ | rhs.flags_);
        }
    };

    /**
* @todo
*/
    class batch_options: public options
    {
    public:
        using options::options;

        /**
         * @todo
         */
        constexpr batch_options operator|(const batch_options &rhs) const noexcept
        {
            return batch_options(this->flags_ | rhs.flags_);
        }
    };

    /**
     * @todo
     */
    class additional_options: public options_interface<operation_specific_flags_t>
    {
    public:
        using options_interface<operation_specific_flags_t>::options_interface;
    };

    /**
     * @todo
     */
    class expected_result_options: public options_interface<result_t>
    {
    public:
        using options_interface<result_t>::options_interface;

        /**
         * @todo
         */
        constexpr expected_result_options operator|(const expected_result_options &rhs) const noexcept
        {
            return expected_result_options(this->flags_ | rhs.flags_);
        }
    };

    /**
     * @todo
     */
    class crc_additional_options: public additional_options
    {
    public:
        using additional_options::additional_options;

        constexpr crc_additional_options() = default;

        constexpr crc_additional_options(crc_flag value):
            additional_options(static_cast<std::underlying_type_t<flag>>(value))
        {
        }

        /**
         * @todo
         */
        constexpr crc_additional_options operator|(const crc_additional_options &rhs) const noexcept
        {
            return crc_additional_options(this->flags_ | rhs.flags_);
        }
    };

    /**
     * @todo
     */
    class copy_crc_additional_options: public additional_options
    {
    public:
        using additional_options::additional_options;

        constexpr copy_crc_additional_options() = default;

        constexpr copy_crc_additional_options(crc_flag value):
            additional_options(static_cast<std::underlying_type_t<flag>>(value))
        {
        }

        /**
         * @todo
         */
        constexpr copy_crc_additional_options operator|(const copy_crc_additional_options &rhs) const noexcept
        {
            return copy_crc_additional_options(this->flags_ | rhs.flags_);
        }
    };

    /**
     * @todo
     */
    class dualcast_additional_options: public additional_options
    {
    public:
        using additional_options::additional_options;

        constexpr dualcast_additional_options() = default;

        constexpr dualcast_additional_options(dualcast_flag value):
            additional_options(static_cast<std::underlying_type_t<flag>>(value))
        {
        }

        /**
         * @todo
         */
        constexpr dualcast_additional_options operator|(const dualcast_additional_options &rhs) const noexcept
        {
            return dualcast_additional_options(this->flags_ | rhs.flags_);
        }
    };

}  // namespace dml::ml

#endif  //DML_COMMON_OPTION_TYPES_HPP
