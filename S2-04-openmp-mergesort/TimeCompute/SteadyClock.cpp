#include"SteadyClock.h"

void SteadyClock::Init()
{


}

void SteadyClock::Release()
{


}


void SteadyClock::Test()
{
  steady_clock::time_point t1 = steady_clock::now();

  std::cout << "printing out 1000 stars...\n";
  for (int i=0; i<1000; ++i) std::cout << "*";
  std::cout << std::endl;

  steady_clock::time_point t2 = steady_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  std::cout << "It took me " << time_span.count() << " seconds.";
  std::cout << std::endl;
}

void SteadyClock::Test_high_resolution()
{
  high_resolution_clock::time_point t1 = high_resolution_clock::now();

  std::cout << "printing out 1000 stars...\n";
  for (int i=0; i<1000; ++i) std::cout << "*";
  std::cout << std::endl;

  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  std::cout << "It took me " << time_span.count() << " seconds.";
  std::cout << std::endl;
}


void SteadyClock::Start()
{
  time_start = steady_clock::now();

}

void SteadyClock::End()
{
  time_end = steady_clock::now();

}

void SteadyClock::Duration(std::string TimeInfo)
{
  time_duration = duration_cast<duration<double>>(time_end - time_start);
  std::cout << TimeInfo<<" It took " << time_duration.count() << " seconds.";
  std::cout << std::endl;
}

void SteadyClock::Start_high()
{
  time_start_H = high_resolution_clock::now();
}

void SteadyClock::End_high()
{
  time_end_H = high_resolution_clock::now();
}

void SteadyClock::Duration_high(std::string TimeInfo)
{
  time_duration_H = duration_cast<duration<double>>(time_end_H - time_start_H);

  std::cout << TimeInfo << "It took " << time_duration_H.count() << " seconds.(high_resolution)";
  std::cout << std::endl;
}
