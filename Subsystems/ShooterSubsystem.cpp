#include "ShooterSubsystem.h"
#include "../Commands/ShooterControlCommand.h"
#include "../Robotmap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem"),
 shootMotor(SHOOT_MOTOR), shootEncoder(SHOOT_ENCODER), shootLoop(shootP, shootI, shootD, this, this),
 shootSolenoid(SHOOT_SOLENOID), tiltSolenoid(SHOOT_TILT_SOLENOID), shootingWheelEnabled(true)
{
	shootLoop.SetInputRange(0.0f, 7000.0f);	//LIMIT SHOOTER WHEEL TO 0-7000 RPM
	shootLoop.SetOutputRange(0.0f, 1.0f);	//LIMIT SHOOTER WHEEL TO ONLY DRIVE FORWARD
	SetSpeed(0.0f);							//SET SHOOTER WHEEL SPEED TO 0
	shootEncoder.Reset();					
	shootEncoder.SetMaxPeriod(1.0f);		
	shootEncoder.Start();
	shootLoop.SetTolerance(0.005f);			//SHOOTER WHEEL RPM TOLERANCE IS 0.5%
	shootLoop.Enable();						//ENABLE SHOOTER WHEEL PID LOOP
}

void ShooterSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new ShooterControlCommand());
}

inline float Map(float minIn, float maxIn, float minOut, float maxOut, float val)
{
	return ((val - minIn) / (maxIn - minIn)) * (maxOut - minOut) + minOut;
}

void ShooterSubsystem::Reset()
{

}

// Set the shoot solenoid to  activate the 2 pistons that elevate the shooter
void ShooterSubsystem::SetTilt(bool tilt) 
{
	tiltSolenoid.Set(!tilt);
}

//Returns shooter wheel speed in RPM
double ShooterSubsystem::PIDGet()
{
	return (30.0f / shootEncoder.GetPeriod());
}

//Do not use
void ShooterSubsystem::PIDWrite(float output)
{
	shootMotor.Set(output * -1.0f);
}

// Turns shooter wheel on (True) or off (false)
void ShooterSubsystem::ToggleShooterWheel(bool state)
{
	shootingWheelEnabled = state;
}

//Sets shooter wheel RPM setpoint for PID Controller
void ShooterSubsystem::SetSpeed(float speed)
{
	//If shooting is true set speed to passed setpoint, otherwise set the shooter wheel to 0 RPM.
	shootLoop.SetSetpoint((shootingWheelEnabled) ? speed : (0.0f));
}

//Toggles the disk feed solenoid between shooting (True) and feeding (False)
void ShooterSubsystem::SetFire(bool fire)
{
	shootSolenoid.Set(fire);
}

//Debug console for ShooterSubsystem. Contains PID Tuning Code.
void ShooterSubsystem::Debug()
{
	std::cout << "Motor Speed: " << shootMotor.Get() << " || Shooter Speed: " << PIDGet() << std::endl;
	std::cout << "Shoot Enabled: " << shootingWheelEnabled << " || Shoot Setpoint: " << shootLoop.GetSetpoint() << std::endl;
	std::cout << " ============= " << std::endl;
		
	/*if (CommandBase::oi->GetTest1() && !derp)
		p += 0.0001f;
	if (CommandBase::oi->GetTest2() && !derp)
		p -= 0.0001f;
	if (CommandBase::oi->GetTest5() && !derp)
		i += 0.0001f;
	if (CommandBase::oi->GetTest6() && !derp)
		i -= 0.0001f;
	if (CommandBase::oi->GetTest3() && !derp)
		d += 0.0001f;
	if (CommandBase::oi->GetTest4() && !derp)
		d -= 0.0001f;
	
	derp = CommandBase::oi->GetTest1() || CommandBase::oi->GetTest2() || CommandBase::oi->GetTest3() || CommandBase::oi->GetTest4() || CommandBase::oi->GetTest5() || CommandBase::oi->GetTest6();

	}
	std::cout << "===========" << std::endl;*/
}
