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

#include "setsugan_occupancy_grid/occupancy_grid_all_value.hpp"

#include <rclcpp_components/register_node_macro.hpp>

namespace setsugan_occupancy_grid
{
    OccupancyGridAllValue::OccupancyGridAllValue (const rclcpp::NodeOptions& node_options)
        : Node ("occupancy_grid_all_value", node_options)
    {
        // 地図送信時の QoS は translate_local を用いる
        occupancy_grid_publisher_ = create_publisher<nav_msgs::msg::OccupancyGrid> (
            "occupancy_grid", rclcpp::QoS (1).reliable ().transient_local ());

        nav_msgs::msg::OccupancyGrid occupancy_grid;

        ////////////////////////////////////////////////////////////////////////////////////////////
        // header
        occupancy_grid.header.stamp    = this->now ();
        occupancy_grid.header.frame_id = "map";

        ////////////////////////////////////////////////////////////////////////////////////////////
        // info
        occupancy_grid.info.map_load_time        = this->now ();
        occupancy_grid.info.resolution           = 0.05;
        occupancy_grid.info.width                = 17;
        occupancy_grid.info.height               = 6;
        occupancy_grid.info.origin.position.x    = 0.0;
        occupancy_grid.info.origin.position.y    = 0.0;
        occupancy_grid.info.origin.position.z    = 0.0;
        occupancy_grid.info.origin.orientation.x = 0.0;
        occupancy_grid.info.origin.orientation.y = 0.0;
        occupancy_grid.info.origin.orientation.z = 0.0;
        occupancy_grid.info.origin.orientation.w = 1.0;

        ////////////////////////////////////////////////////////////////////////////////////////////
        // data

        // -1 ~ 100 まで値を入れる
        for (int i = -1 ; i <= 100; ++i)
        {
            occupancy_grid.data.push_back (i);
        }

        // 任意の位置に値を入れる
        // const int mx = 2;
        // const int my = 2;

        // occupancy_grid.data[my * occupancy_grid.info.width + mx] = 100;

        ////////////////////////////////////////////////////////////////////////////////////////////
        // publish
        occupancy_grid_publisher_->publish (occupancy_grid);

        RCLCPP_INFO (this->get_logger (), "occupancy_grid_all_value node has been initialized.");
    }
} // namespace setsugan_occupancy_grid

RCLCPP_COMPONENTS_REGISTER_NODE (setsugan_occupancy_grid::OccupancyGridAllValue)
