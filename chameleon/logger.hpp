#ifndef CHAMELEON_LOGGER
#define CHAMELEON_LOGGER
#include <string>
using std::string;
using std::to_string;

#include <chrono>
#include <mutex>
using std::mutex;

#include <iostream>
using std::cout;
using std::endl;

class Logger {
		private:
			mutex f;
			FILE *log_file = NULL;
			int file_ok = 0;
			int debug_ok = 0;

			void BASE(string status, string text) {
				time_t now = time(&now);
				struct tm ti;
				#if _WIN32
				localtime_s(&ti, &now);
				#else
				localtime_r(&now,&ti);
				#endif
				std::chrono::time_point<std::chrono::system_clock, std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
				auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
				std::time_t timestamp = tmp.count();
				string time_date = "[" + to_string(ti.tm_year + 1900)
					+ "-" + to_string(ti.tm_mon + 1)
					+ "-" + to_string(ti.tm_mday)
					+ " " + to_string(ti.tm_hour)
					+ ":" + to_string(ti.tm_min)
					+ ":" + to_string(ti.tm_sec)
					+ "." + to_string(timestamp)
					+ "] ";
				string all = time_date + "[" + status + "] " + text + "\n";

				cout << all;
				if(file_ok) {
					if(this->f.try_lock()) {
						fprintf(this->log_file, "%s", all.c_str());
						this->f.unlock();
					}
				}
			}
		public:
			Logger(const char *file_path, int debug = 0, const char *mode = "a") {
				this->debug_ok = debug;
				this->log_file = fopen(file_path, mode);
				if(this->log_file != NULL) this->file_ok = 1;
				else perror("File can not create"), exit(EXIT_FAILURE);
			}
			Logger() {}
			~Logger() {}

			void info(string text) { this->BASE("INFO", text); }
			void debug(string text) {
				if(this->debug_ok) this->BASE("DEBUG", text);
			}
			void warn(string text) { this->BASE("WARN", text); }
			void fatal(string text) { this->BASE("FATAL", text); }
			void error(string text) { this->BASE("ERROR", text); }
			void setDebug(int o) {
				this->debug_ok = o;
			}
		};

#endif