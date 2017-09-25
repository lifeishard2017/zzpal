#include <iostream>

#include "ocilib.hpp"
#include "log.h"

using namespace ocilib;

void testOCI()
{
    try
    {
        Environment::Initialize();

        Connection con("orcl", "sys", "1",Environment::SessionSysDba);

        Statement st(con);

        st.Execute("select rownum, cursor(select sysdate from dual) from (select 1 from dual connect by level <= 10)");

        Resultset rs = st.GetResultset();

        while (rs++)
        {
            Statement st2 = rs.Get<Statement>(2);
            Resultset rs2 = st2.GetResultset();

            while (rs2++)
            {
                std::cout << "Table : " << rs.Get<ostring>(1) << ", Date : " << rs2.Get<ostring>(1) << std::endl;
            }
        }

    }
    catch (std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    Environment::Cleanup();
}

void testBoostLog()
{
    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
}
int main(void)
{
    testOCI();
    testBoostLog();
    return 0;
}
