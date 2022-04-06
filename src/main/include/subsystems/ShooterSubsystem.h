#pragma once

#include <frc2/command/SubsystemBase.h>

#include "Constants.h"

class ShooterSubsystem : public frc2::SubsystemBase
{
  public:
    ShooterSubsystem();

    void setShooterSpeed(double speed);

  private:
    // motor declarations go here
};
