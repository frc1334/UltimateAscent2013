#include "ShooterSubsystem.h"
#include "../Commands/ShooterControlCommand.h"
#include "../Robotmap.h"

ShooterSubsystem::ShooterSubsystem() : Subsystem("ShooterSubsystem"),
 shootMotor(SHOOT_MOTOR), shootEncoder(SHOOT_ENCODER), shootLoop(shootP, shootI, shootD, this, this),
 shootSolenoid(SHOOT_SOLENOID), tiltSolenoid(SHOOT_TILT_SOLENOID), g_timer()
{
	shootLoop.SetInputRange(0.0f, 7000.0f);	//LIMIT SHOOTER WHEEL TO 0-7000 RPM
	shootLoop.SetOutputRange(0.0f, 1.0f);	//LIMIT SHOOTER WHEEL TO ONLY DRIVE FORWARD
	SetSpeed(0.0f);							//SET SHOOTER WHEEL SPEED TO 0
	shootEncoder.Reset();					
	shootEncoder.SetMaxPeriod(1.0f);		
	shootEncoder.Start();
	shootLoop.SetAbsoluteTolerance(250.0f);			//SHOOTER WHEEL RPM TOLERANCE is 200 RPM
	shootLoop.Enable();						//ENABLE SHOOTER WHEEL PID LOOP
#ifdef DEBUG_CONSOLE
	debug_console_delay_counter = 0;
#endif
	g_timer.Reset();
	g_timer.Stop();
}

void ShooterSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new ShooterControlCommand());
}

inline float Map(float minIn, float maxIn, float minOut, float maxOut, float val)
{
	return ((val - minIn) / (maxIn - minIn)) * (maxOut - minOut) + minOut;
}

// Set the shoot solenoid to  activate the 2 pistons that elevate the shooter
void ShooterSubsystem::SetTilt(bool tilt) 
{
	tiltSolenoid.Set(tilt);
}

//Returns shooter wheel speed in RPM
double ShooterSubsystem::PIDGet()
{
	return (30.0f / shootEncoder.GetPeriod());//663816438156156437541375643765431654514537541354
}

//Do not use
void ShooterSubsystem::PIDWrite(float output)
{
	shootMotor.Set(output * -1.0f);
}

//Sets shooter wheel RPM setpoint for PID Controller
void ShooterSubsystem::SetSpeed(float speed)
{
	shootLoop.SetSetpoint(speed);
}

//Toggles the disk feed solenoid between shooting (True) and feeding (False)
void ShooterSubsystem::SetFire(bool fire)
{
	shootSolenoid.Set(fire);
}

bool ShooterSubsystem::Jiggly()
{
	static bool timer_running = false, has_risen = false;
	if (!timer_running && !has_risen)
	{
		g_timer.Start();
		SetTilt(false);
	}
	if (!has_risen && g_timer.HasPeriodPassed(0.25f))
	{
		SetTilt(true);
		has_risen = true;
		g_timer.Reset();
	}
	if (has_risen && g_timer.HasPeriodPassed(0.25f))
	{
		g_timer.Reset();
		g_timer.Stop();
		return true;
	}
	return false;
}

bool ShooterSubsystem::ShootDiscs(unsigned int shots_fire)
{
	static unsigned int shots_fired = 0;
	static bool triggered_shot = false;
	cout << g_timer.Get() << " " << shots_fired << " " << triggered_shot << " " << shootLoop.OnTarget() << endl;
	if (shots_fired < shots_fire && !triggered_shot)
		if (shootLoop.OnTarget())
		{
			SetFire(triggered_shot = true);
			g_timer.Start();
		}
	if (shots_fired >= shots_fire)
	{
		shots_fired = 0;
		g_timer.Stop();
		triggered_shot = false;
		SetFire(false);
		return true;
	}
	if (triggered_shot && g_timer.Get() > 0.25f)
		SetFire(false);
	if (triggered_shot && g_timer.Get() > 1.0f)
	{
		triggered_shot = false;
		++shots_fired;
		g_timer.Reset();
		g_timer.Stop();
	}
	return false;
}

//Debug console for ShooterSubsystem. Contains PID Tuning Code.
void ShooterSubsystem::Debug()
{
	std::cout << (30.0f / shootEncoder.GetPeriod()) << " " << g_timer.Get() << std::endl;
	/*if(debug_console_delay_counter > 10)
	{
	std::cout << "Motor Speed: " << shootMotor.Get() << " || Shooter Speed: " << PIDGet() << " || Shoot Solenoid: " << shootSolenoid.Get() << std::endl;
	std::cout << "Shoot Setpoint: " << shootLoop.GetSetpoint() << " || Autofire button: " << CommandBase::oi->GetAutoFire() << " || Autofire bool:" << std::endl;
	std::cout << " ============= " << std::endl;
	debug_console_delay_counter=0;
	}
	else
		debug_console_delay_counter++;*/
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
