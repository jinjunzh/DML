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

#ifndef DML_MIDDLE_LAYER_DISPATCHER_HW_DEVICE_HPP_
#define DML_MIDDLE_LAYER_DISPATCHER_HW_DEVICE_HPP_

#include <array>

#include "dml/dmldefs.h"
#include "hw_queue.hpp"

#ifdef DML_HW
#include "hardware_definitions.h"
#include "own_dsa_accel_constants.h"

namespace dml::ml::dispatcher {

class hw_device final {

    static constexpr uint32_t max_working_queues = MAX_WORK_QUEUE_COUNT;

    using queues_container_t = std::array<hw_queue, max_working_queues>;

public:
    using descriptor_t = void;

    hw_device() noexcept = default;

    void fill_hw_context(dsahw_context_t *hw_context_ptr) const noexcept;

    [[nodiscard]] auto enqueue_descriptor(const dsahw_descriptor_t *desc_ptr) const noexcept -> dsahw_status_t;

    [[nodiscard]] auto initialize_new_device(descriptor_t *device_descriptor_ptr) noexcept -> dsahw_status_t;

    [[nodiscard]] auto size() const noexcept -> size_t;

    [[nodiscard]] auto numa_id() const noexcept -> uint64_t;

    [[nodiscard]] auto begin() const noexcept -> queues_container_t::const_iterator;

    [[nodiscard]] auto end() const noexcept -> queues_container_t::const_iterator;

protected:
    auto block_on_fault_support() const noexcept -> uint8_t;

    auto overlapping_copy_support() const noexcept -> uint8_t;

    auto memory_cache_control_support() const noexcept -> uint8_t;

    auto flush_cache_control_support() const noexcept -> uint8_t;

    auto interrupt_handle_request() const noexcept -> uint8_t;

    auto destination_readback_support() const noexcept -> uint8_t;

    auto descriptor_readback_support() const noexcept -> uint8_t;

    auto max_transfer_size() const noexcept -> uint32_t;

    auto max_batch_size() const noexcept -> uint32_t;

    auto message_size() const noexcept -> uint16_t;

    auto configuration_support() const noexcept -> uint8_t;

    auto max_descriptors() const noexcept -> uint8_t;

private:
    queues_container_t working_queues_   = {};    /**< Set of available HW working queues */
    uint32_t           queue_count_      = 0u;    /**< Number of working queues that are available */
    uint64_t           gen_cap_register_ = 0u;    /**< GENCAP register content */
    uint64_t           numa_node_id_     = 0u;    /**< NUMA node id of the device */
    uint32_t           version_          = 0u;    /**< Version of discovered device */
};

}

#endif
#endif //DML_MIDDLE_LAYER_DISPATCHER_HW_DEVICE_HPP_
