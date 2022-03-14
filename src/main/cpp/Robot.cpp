#include <frc/Joystick.h>
#include <frc/TimedRobot.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"

class Robot : public frc::TimedRobot {
  WPI_TalonFX m_frontLeft{12};
  WPI_TalonFX m_rearLeft{13};
  WPI_TalonFX m_frontRight{14};
  WPI_TalonFX m_rearRight{15};
  
  frc::MotorControllerGroup m_left{m_frontLeft, m_rearLeft};
  frc::MotorControllerGroup m_right{m_frontRight, m_rearRight};
  
  frc::DifferentialDrive m_robotDrive{m_left, m_right};

  rev::CANSparkMax m_climberRight{10, rev::CANSparkMax::MotorType::kBrushless};
  rev::CANSparkMax m_climberRLeft{11, rev::CANSparkMax::MotorType::kBrushless};

  frc::Joystick m_stick{0};

  void RobotInit() override {
    m_right.SetInverted(true);
  }

  void TeleopPeriodic() override {
    if(m_stick.GetRawButton(1)){
      m_climberRight.Set(m_stick.GetY());
      m_climberRLeft.Set(m_stick.GetY());
    }
    else{
      m_robotDrive.ArcadeDrive(m_stick.GetY(), m_stick.GetX());
      m_climberRight.Set(0);
      m_climberRLeft.Set(0);
    }
  }
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
