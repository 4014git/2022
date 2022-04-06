#pragma once

#include <frc/Joystick.h>
#include <frc2/command/FunctionalCommand.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/ParallelCommandGroup.h>
#include <frc2/command/RunCommand.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/button/JoystickButton.h>

#include "subsystems/ClimberSubsystem.h"
#include "subsystems/DrivetrainSubsystem.h"
#include "subsystems/IntakeSubsystem.h"
#include "subsystems/ShooterSubsystem.h"



class RobotContainer
{
  public:
    RobotContainer();
    frc2::Command *GetAutonomousCommand();

  private:
    frc::Joystick m_driverController{OIConstants::driverControllerPort};
    frc::Joystick m_operatorController{OIConstants::operatorControllerPort};

    DrivetrainSubsystem m_drive;
    ClimberSubsystem m_climber;
    IntakeSubsystem m_intake;
    ShooterSubsystem m_shooter;

    frc2::InstantCommand m_LeftClimberUp{[this] { m_climber.setLeftSpeed(ClimberConstants::kManualClimberSpeed); },
                                         {&m_climber}};
    frc2::InstantCommand m_LeftClimberDown{[this] { m_climber.setLeftSpeed(-ClimberConstants::kManualClimberSpeed); },
                                           {&m_climber}};
    frc2::InstantCommand m_RightClimberUp{[this] { m_climber.setRightSpeed(ClimberConstants::kManualClimberSpeed); },
                                          {&m_climber}};
    frc2::InstantCommand m_RightClimberDown{[this] { m_climber.setRightSpeed(-ClimberConstants::kManualClimberSpeed); },
                                            {&m_climber}};
    frc2::InstantCommand m_ClimberByJoystick{[this] { m_climber.setSpeed(-m_operatorController.GetY()); },
                                            {&m_climber}};
    
    // todo: add instant commands here and the joystick bindings in RobotContainer.cpp

    frc2::InstantCommand m_changeSquareInputPressed{[this] { m_drive.SetSquareInputs(!DriveConstants::kDefualtSquareInputs); }, {&m_drive}};
    frc2::InstantCommand m_changeSquareInputReleased{[this] { m_drive.SetSquareInputs(DriveConstants::kDefualtSquareInputs); }, {&m_drive}};


    // frc2::ParallelCommandGroup m_ClimberUp{
    //     frc2::FunctionalCommand(
    //         [this] { m_climber.ResetLeftEncoder(); },
    //         [this] { m_climber.setLeftSpeed(ClimberConstants::kClimberSpeed); },
    //         [this](bool interrupted) { m_climber.setLeftSpeed(0); },
    //         [this] { return m_climber.getLeftEncoderDistance() >= ClimberConstants::kClimberDistanceInches; }),
    //     frc2::FunctionalCommand(
    //         [this] { m_climber.ResetRightEncoder(); },
    //         [this] { m_climber.setRightSpeed(ClimberConstants::kClimberSpeed); },
    //         [this](bool interrupted) { m_climber.setRightSpeed(0); },
    //         [this] { return m_climber.getRightEncoderDistance() >= ClimberConstants::kClimberDistanceInches; })};

    // frc2::ParallelCommandGroup m_ClimberDown{
    //     frc2::FunctionalCommand([this] {}, [this] { m_climber.setLeftSpeed(-ClimberConstants::kClimberSpeed); },
    //                             [this](bool interrupted) { m_climber.setLeftSpeed(0); },
    //                             [this] { return m_climber.getLeftEncoderDistance() <= 0; }),
    //     frc2::FunctionalCommand([this] {}, [this] { m_climber.setRightSpeed(-ClimberConstants::kClimberSpeed); },
    //                             [this](bool interrupted) { m_climber.setRightSpeed(0); },
    //                             [this] { return m_climber.getRightEncoderDistance() <= 0; })};

    frc2::SequentialCommandGroup m_Auto{
        frc2::FunctionalCommand(
            [this] { m_drive.ResetEncoders(); }, [this] { m_drive.ArcadeDrive(AutoConstants::kAutoDriveSpeed, 0); },
            [this](bool interrupted) { },
            [this] { return m_drive.GetAverageEncoderDistance() >= AutoConstants::kAutoDriveDistanceInches; },
            {&m_drive}),
        frc2::FunctionalCommand([this] {}, [this] { m_drive.ArcadeDrive(-AutoConstants::kAutoDriveSpeed, 0); },
                                [this](bool interrupted) { m_drive.ArcadeDrive(0, 0); },
                                [this] { return m_drive.GetAverageEncoderVelocity() <= 0; }, {&m_drive})};
    
    // frc2::SequentialCommandGroup m_shooter_Auto {
    //   frc2::FunctionalCommand( // First, the robot drives backwards with the intake on to collect a second cargo
    //     [this] {m_intake.setSpeed(0.75);}, [this] { m_drive.ArcadeDrive(AutoConstants::kAutoDriveSpeed, 0); },
    //     [this] (bool interrupted) { },
    //     [this] {return m_drive.GetAverageEncoderDistance() >= AutoConstants::kAutoDriveDistanceInches;}
    //   ),
    //   frc2::FunctionalCommand( // Then, it shoots both cargos by continuously running the shooter motor
    //     [this] {m_shooter.setShooterSpeed(0.75);}, [this] {;},
    //     [this] (bool interrupted) { },
    //     [this] { return false ;}
    //   )
    // };
    // ^ for use when we have a functional shooter
    void ConfigureButtonBindings();
};
