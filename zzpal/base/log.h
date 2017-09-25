#include <boost/log/core.hpp>  
#include <boost/log/trivial.hpp>  
#include <boost/log/expressions.hpp>  
#include <boost/log/sinks/text_file_backend.hpp>  
#include <boost/log/utility/setup/file.hpp>  
#include <boost/log/utility/setup/common_attributes.hpp>  
#include <boost/log/sources/severity_logger.hpp>  
#include <boost/log/sources/record_ostream.hpp>  

#define LOG_T BOOST_LOG_TRIVIAL(trace)
#define LOG_D BOOST_LOG_TRIVIAL(debug)
#define LOG_W BOOST_LOG_TRIVIAL(warning)
#define LOG_E BOOST_LOG_TRIVIAL(error)
#define LOG_F BOOST_LOG_TRIVIAL(fatal)

namespace logging = boost::log;  
namespace src = boost::log::sources;  
namespace sinks = boost::log::sinks;  
namespace keywords = boost::log::keywords;  

namespace zzpal{

class Logger{

public:
    enum severity_level
    {
        normal,
        notification,
        warning,
        error,  
        critical
    };
    
public:
    static void init(){}

    Logger(){}

    void disable(){}

    };
}
