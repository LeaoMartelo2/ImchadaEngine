

template <typename... Args>
void Instance::imchada_log(LogType level, const std::string &format, Args... args) {

    if (get_logging_state() == false) {
        return;
    }

    bool debug_check = get_debug_state();

    std::string final_string = get_log_level_string(level);

    // use std::format to format the to_string
    std::string formated_message = fmt::format(format, args...);

    // get sys time
    auto now = std::chrono::system_clock::now();
    // convert time_point to time_t
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    //    timezone stuff
    std::tm *local_time = std::localtime(&now_c);

    int day = local_time->tm_mday;
    int month = local_time->tm_mon + 1;    // 0 indexed
    int year = local_time->tm_year + 1900; // timestamped since 1900 so add 1900 to get current year
    int hour = local_time->tm_hour;        // 24-hour format
    int minute = local_time->tm_min;
    int second = local_time->tm_sec;

    std::fstream file("latest.log", std::ios::app); // open file in append mode

    if (!file.is_open()) {

        file.open("latest.log", std::ios::out); // creates the file in output mode if it does
                                                // not exist / failed to open in append mode
    }

    if (debug_check == false && level == LogType::DEBUG) {
        return;
    }

    file << "[" << year << "/" << month << "/" << day << "]"
         << "[" << hour << ":" << minute << ":" << second << "]"
         << formated_message << '\n';

    // this should end up printing like this
    //[year/month/day] [hour:minute:second] <LogType> <message>

    file.close();
}
