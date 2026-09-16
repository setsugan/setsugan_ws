// Copyright 2026 Riku Yukimaru
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SETSUGAN_OCCUPANCY_GRID__OCCUPANCY_GRID_ALL_VALUE_HPP_
#define SETSUGAN_OCCUPANCY_GRID__OCCUPANCY_GRID_ALL_VALUE_HPP_

#include <rclcpp/rclcpp.hpp>

namespace setsugan_occupancy_grid
{
    class OccupancyGridAllValue : public rclcpp::Node
    {
    public:
        explicit OccupancyGridAllValue (const rclcpp::NodeOptions& node_options);

        
    };
} // namespace setsugan_occupancy_grid

#endif // SETSUGAN_OCCUPANCY_GRID__OCCUPANCY_GRID_ALL_VALUE_HPP_
