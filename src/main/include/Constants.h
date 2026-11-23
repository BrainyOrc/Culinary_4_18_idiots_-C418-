#pragma once
 
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace OperatorConstants 
{

inline constexpr int kDriverControllerPort = 0;
inline constexpr int kDriverControllerPortTank = 1;

//Drive:
inline constexpr int kC418DriveLM1 = 2;
inline constexpr int kC418DriveLM2 = 3;
inline constexpr int kC418DriveRM1 = 4;
inline constexpr int kC418DriveRM2 = 5;

}  // namespace OperatorConstants
