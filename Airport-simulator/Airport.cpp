#include "Header.h"
#include "RANDOM.H"

// Functions first:
bool Runway::check_fuel_rate(Plane &current, int fuel_rate)
{
   if (current.get_fuel() < fuel_rate)
      return false;
   return true;
}

void initialize(int &end_time, int &queue_limit,
                double &arrival_rate, double &departure_rate)
/*
Pre:  The user specifies the number of time units in the simulation,
      the maximal queue sizes permitted,
      and the expected arrival and departure rates for the airport.
Post: The program prints instructions and initializes the parameters
      end_time, queue_limit, arrival_rate, and departure_rate to
      the specified values.
Uses: utility function user_says_yes
*/

{
   cout << "This program simulates an airport with only one runway." << endl
        << "One plane can land or depart in each unit of time." << endl;
   cout << "Up to what number of planes can be waiting to land "
        << "or take off at any time?:  " << flush;
   cin >> queue_limit;

   cout << "How many units of time will the simulation run?:  " << flush;
   cin >> end_time;

   bool acceptable;
   do
   {
      cout << "Expected number of arrivals per unit time?:  " << flush;
      cin >> arrival_rate;
      cout << "Expected number of departures per unit time?:  " << flush;
      cin >> departure_rate;
      if (arrival_rate < 0.0 || departure_rate < 0.0)
         cerr << "These rates must be nonnegative." << endl;
      else
         acceptable = true;

      if (acceptable && arrival_rate + departure_rate > 1.0)
         cerr << "Safety Warning: This airport will become saturated. " << endl;

   } while (!acceptable);
}

void run_idle(int time)
/*
Post: The specified time is printed with a message that the runway is idle.
*/
{
   cout << time << ": Runway is idle." << endl;
}

// Class Runway Methods:
//--------------------------------------------
Runway::Runway(int limit)
/*
Post:  The Runway data members are initialized to record no
       prior Runway use and to record the limit on queue sizes.
*/

{
   queue_limit = limit;
   num_land_requests = num_takeoff_requests = 0;
   num_landings = num_takeoffs = 0;
   num_land_refused = num_takeoff_refused = 0;
   num_land_accepted = num_takeoff_accepted = 0;
   land_wait = takeoff_wait = idle_time = 0;
}

Error_code Runway::can_land(const Plane &current)
/*
Post:  If possible, the Plane current is added to the
       landing Queue; otherwise, an Error_code of overflow is
       returned. The Runway statistics are updated.
Uses:  class Extended_queue.
*/

{
   Error_code result;
   if (landing.size() < queue_limit)
      result = landing.append(current);
   else
      result = fail;
   num_land_requests++;

   if (result != success)
      num_land_refused++;
   else
      num_land_accepted++;

   return result;
}

Error_code Runway::can_depart(const Plane &current)
/*
Post:  If possible, the Plane current is added to the
       takeoff Queue; otherwise, an Error_code of overflow is
       returned. The Runway statistics are updated.
Uses:  class Extended_queue.
*/

{
   Error_code result;
   if (takeoff.size() < queue_limit)
      result = takeoff.append(current);
   else
      result = fail;
   num_takeoff_requests++;
   if (result != success)
      num_takeoff_refused++;
   else
      num_takeoff_accepted++;

   return result;
}

Runway_activity Runway::activity(int time, Plane &moving)
/*
Post:  If the landing Queue has entries, its front
       Plane is copied to the parameter moving
       and a result  land is returned. Otherwise,
       if the takeoff Queue has entries, its front
       Plane is copied to the parameter moving
       and a result  takeoff is returned. Otherwise,
       idle is returned. Runway statistics are updated.
Uses:  class Extended_queue.
*/

{
   Runway_activity in_progress;
   if (!landing.empty())
   {
      landing.retrieve(moving);
      land_wait += time - moving.started();
      if (moving.get_fuel() < 1)
      {
         num_dropped++;
         in_progress = drop;
      }
      num_landings++;
      in_progress = land;
      landing.serve();
   }
   else if (!takeoff.empty())
   {
      takeoff.retrieve(moving);
      takeoff_wait += time - moving.started();
      num_takeoffs++;
      in_progress = take_off;
      takeoff.serve();
   }
   else
   {
      idle_time++;
      in_progress = idle;
   }
   return in_progress;
}

Runway_activity Runway::activity2(int time, Plane &moving)
/*
Post:  If the landing Queue has entries, its front
       Plane is copied to the parameter moving
       and a result  land is returned. Otherwise,
       if the takeoff Queue has entries, its front
       Plane is copied to the parameter moving
       and a result  takeoff is returned. Otherwise,
       idle is returned. Runway statistics are updated.
Uses:  class Extended_queue.
*/

{
   Runway_activity in_progress;
   if (!landing.empty())
   {
      landing.retrieve(moving);
      land_wait += time - moving.started();
      num_landings++;
      in_progress = land;
      landing.serve();
   }
   if (!takeoff.empty())
   {
      takeoff.retrieve(moving);
      takeoff_wait += time - moving.started();
      num_takeoffs++;
      in_progress = take_off;
      takeoff.serve();
   }
   if (landing.empty() && takeoff.empty())
   {
      idle_time++;
      in_progress = idle;
   }
   return in_progress;
}

void Runway::shut_down(int time) const
/*
Post: Runway usage statistics are summarized and printed.
*/

{
   cout << "Simulation has concluded after " << time << " time units." << endl
        << "Total number of planes processed "
        << (num_land_requests + num_takeoff_requests) << endl
        << "Total number of planes asking to land "
        << num_land_requests << endl
        << "Total number of planes asking to take off "
        << num_takeoff_requests << endl
        << "Total number of planes accepted for landing "
        << num_land_accepted << endl
        << "Total number of planes accepted for takeoff "
        << num_takeoff_accepted << endl
        << "Total number of planes refused for landing "
        << num_land_refused << endl
        << "Total number of planes refused for takeoff "
        << num_takeoff_refused << endl
        << "Total number of planes that landed "
        << num_landings << endl
        << "Total number of planes that took off "
        << num_takeoffs << endl
        << "Total number of planes left in landing queue "
        << landing.size() << endl
        << "Total number of planes left in takeoff queue "
        << takeoff.size() << endl;
   cout << "Percentage of time runway idle "
        << 100.0 * ((float)idle_time) / ((float)time) << "%" << endl;
   cout << "Average wait in landing queue "
        << ((float)land_wait) / ((float)num_landings) << " time units";
   cout << endl
        << "Average wait in takeoff queue "
        << ((float)takeoff_wait) / ((float)num_takeoffs)
        << " time units" << endl;
   cout << "Average observed rate of planes wanting to land "
        << ((float)num_land_requests) / ((float)time)
        << " per time unit" << endl;
   cout << "Average observed rate of planes wanting to take off "
        << ((float)num_takeoff_requests) / ((float)time)
        << " per time unit" << endl;
}

void Runway::short_shut_down(int time) const
{
   cout << "Simulation has concluded after " << time << " time units." << endl
        << "Total number of planes processed "
        << (num_land_requests + num_takeoff_requests) << endl
        << "Total number of planes that landed "
        << num_landings << endl
        << "Total number of planes that took off "
        << num_takeoffs << endl
        << "Total number of planes left in landing queue "
        << landing.size() << endl
        << "Total number of planes left in takeoff queue "
        << takeoff.size() << endl
        << "Total planes dropped "
        << num_dropped << endl;
}
int Runway::get_landing_size() const
{
   return landing.size();
}

int Runway::get_takeoff_size() const
{
   return takeoff.size();
}

bool Runway::is_takeoff_empty()
{
   if (takeoff.empty())
      return true;
   return false;
}

bool Runway::is_landing_empty()
{
   if (landing.empty())
      return true;
   return false;
}

bool Runway::is_takeoff_full()
{
   return takeoff.full();
}

bool Runway::is_landing_full()
{
   return landing.full();
}

void Runway::add_landing()
{
   num_land_requests++;
   num_landings++;
}

void Runway::add_takeoff()
{
   num_takeoff_requests++;
   num_takeoffs++;
}

void Runway::add_drop()
{
   num_dropped++;
}

// Class Plane Methods:
//--------------------------------------------

Plane::Plane(int flt, int time, Plane_status status)
/*
Post:  The Plane data members flt_num, clock_start,
       and state are set to the values of the parameters flt,
       time and status, respectively.
*/

{
   flt_num = flt;
   clock_start = time;
   state = status;
   cout << "Plane number " << flt << " ready to ";
   if (status == arriving)
      cout << "land." << endl;
   else
      cout << "take off." << endl;
}

Plane::Plane()
/*
Post:  The Plane data members flt_num, clock_start,
       state are set to illegal default values.
*/
{
   flt_num = -1;
   clock_start = -1;
   state = null;
}

void Plane::refuse() const
/*
Post: Processes a Plane wanting to use Runway, when
      the Queue is full.
*/

{
   cout << "Plane number " << flt_num;
   if (state == arriving)
      cout << " directed to another airport" << endl;
   else
      cout << " told to try to takeoff again later" << endl;
}

void Plane::land(int time) const
/*
Post: Processes a Plane that is landing at the specified time.
*/

{
   int wait = time - clock_start;
   cout << time << ": Plane number " << flt_num << " landed after "
        << wait << " time unit" << ((wait == 1) ? "" : "s")
        << " in the takeoff queue." << endl;
}

void Plane::fly(int time) const
/*
Post: Process a Plane that is taking off at the specified time.
*/

{
   int wait = time - clock_start;
   cout << time << ": Plane number " << flt_num << " took off after "
        << wait << " time unit" << ((wait == 1) ? "" : "s")
        << " in the takeoff queue." << endl;
}

int Plane::started() const
/*
Post: Return the time that the Plane entered the airport system.
*/
{
   return clock_start;
}

void Plane::random_fuel()
{
   Random variable;
   fuel = variable.poisson(6);
}

void Plane::decrease_fuel()
{
   fuel--;
}

int Plane::get_fuel() const
{
   return fuel;
}

void Plane::drop(int time) const
{
   int wait = time - clock_start;
   cout << time << ": Plane number " << flt_num << " dropped after "
        << wait << " time unit" << ((wait == 1) ? "" : "s")
        << " in the takeoff queue." << endl;
}
