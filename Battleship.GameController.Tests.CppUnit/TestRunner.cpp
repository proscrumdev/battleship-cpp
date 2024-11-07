#include <cppunit/XmlOutputter.h>
#include <cppunit/TextOutputter.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <stdlib.h>
#include <cstring>

using namespace std;

int main (int argc, char* argv[])
{
    // Informiert Test-Listener ueber Testresultate
    CPPUNIT_NS :: TestResult testresult;

    // Listener zum Sammeln der Testergebnisse registrieren
    CPPUNIT_NS :: TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // Listener zur Ausgabe der Ergebnisse einzelner Tests
    CPPUNIT_NS :: BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // Test-Suite ueber die Registry im Test-Runner einfuegen
    CPPUNIT_NS :: TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS :: TestFactoryRegistry :: getRegistry ().makeTest ());
    testrunner.run (testresult);

    if (argc == 2 && strcmp(argv[1],"XML") == 0)
    {
        ofstream xmlFileOut("cpptestresults.xml");
        CPPUNIT_NS :: XmlOutputter xmlOutputter (&collectedresults, xmlFileOut);
        xmlOutputter.write ();
    }
    else
    {
        CPPUNIT_NS :: TextOutputter textOutputter (&collectedresults, std::cerr);
        textOutputter.write ();        
    }
    // // Resultate im Compiler-Format ausgeben
    // CPPUNIT_NS :: CompilerOutputter compileroutputter (&collectedresults, std::cerr);
    // compileroutputter.write ();

    // CPPUNIT_NS :: XmlOutputter xmlOutputter (&collectedresults, std::cerr);
    // xmlOutputter.write ();

    CPPUNIT_NS :: TextOutputter textOutputter (&collectedresults, std::cerr);
    textOutputter.write ();

    // Rueckmeldung, ob Tests erfolgreich waren
    return collectedresults.wasSuccessful () ? 0 : 1;
}  