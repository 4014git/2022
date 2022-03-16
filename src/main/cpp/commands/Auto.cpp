// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/Auto.h"

using namespace AutoConstants;

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
Auto::Auto(DrivetrainSubsystem* m_drive) {
  AddCommands(
    DriveDistance(m_drive,kAutoDriveForwardDistanceInches,kAutoDriveSpeed),
    DriveDistance(m_drive,-kAutoDriveForwardBackInches,-kAutoDriveSpeed)
  );
}
