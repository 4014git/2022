#pragma once

#include <frc/Joystick.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/button/JoystickButton.h>

#include "subsystems/DrivetrainSubsystem.h"
#include "subsystems/ClimberSubsystem.h"
#include "commands/Auto.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer
{
public:
  RobotContainer();
  frc2::Command *GetAutonomousCommand();

private:
  frc::Joystick m_driverController{OIConstants::driverControllerPort};

  DrivetrainSubsystem m_drive;
  ClimberSubsystem m_climber;

  Auto m_Auto{&m_drive};

  frc2::InstantCommand m_LeftClimberUp{[this]
                                       { m_climber.setLeftSpeed(.5); },
                                       {&m_climber}};
  frc2::InstantCommand m_LeftClimberStop{[this]
                                         { m_climber.setLeftSpeed(0); },
                                         {&m_climber}};
  frc2::InstantCommand m_LeftClimberDown{[this]
                                         { m_climber.setLeftSpeed(-.5); },
                                         {&m_climber}};
  frc2::InstantCommand m_RightClimberUp{[this]
                                        { m_climber.setRightSpeed(.5); },
                                        {&m_climber}};
  frc2::InstantCommand m_RightClimberStop{[this]
                                          { m_climber.setRightSpeed(0); },
                                          {&m_climber}};
  frc2::InstantCommand m_RightClimberDown{[this]
                                          { m_climber.setRightSpeed(-.5); },
                                          {&m_climber}};

  void ConfigureButtonBindings();
};
