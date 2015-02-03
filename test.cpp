#include <memory>
#include "catch.hpp"
#include "src.hpp"
SCENARIO("Creation and settings properties for single state", "[State]"){
  State s;

  GIVEN("State is created"){
    WHEN("Empty state is not set any values"){
      THEN("State name is empty string"){
        REQUIRE(s.getName() == "");
      }
      THEN("State cannot handle messages"){
        Message m;
        REQUIRE(s.handleMessage(m) == false);
      }
      THEN("State is given name"){
       const Text stateName = "State under test";
        s.setName(stateName);
        REQUIRE(s.getName() == stateName);
        AND_THEN("State can handle message"){
          Message m("Hello moto!");
          REQUIRE(s.handleMessage(m) == true);
        }
      }
    }
  }
  GIVEN("Second state is created"){
    State s2;
    s2.setName("Second state");

    THEN("States can be assigned"){
      REQUIRE(s != s2);
      s = s2;
      REQUIRE(s == s2);
    }
  }
}
SCENARIO("StateMachine is populated with States", "[StateMachine] [Basic]"){
  Message m("Message payload");

  GIVEN("StateMachine is created"){
    StateMachine sm("test state machine");

    WHEN("is not populated") {
      THEN("shall return size == 0"){
        REQUIRE(sm.size() == 0);
      }
      THEN("shall return that is empty"){
        REQUIRE(sm.isEmpty() == true);
      }
      THEN("cannot be started"){
        REQUIRE(sm.start() == false);
      }
      THEN("cannot be stopped"){
        REQUIRE(sm.stop() == false);
      }
      THEN("is not running"){
        REQUIRE(sm.isRunning() == false);
      }
    }

    WHEN("added one default state"){
      auto default_constructed_state = std::make_shared<State>();
      sm.addState(*default_constructed_state);

      THEN("still is not running"){
        REQUIRE(sm.isRunning() == false);
        AND_THEN("cannot be stopped"){
          REQUIRE(sm.stop() == false);
        }
      }
      THEN("size of StateMachine shall return 1"){
        REQUIRE(sm.size() == 1);
      }
      THEN("shall not return that is empty"){
        REQUIRE(sm.isEmpty() == false);
      }
      THEN("its only state is default state")
      {
        REQUIRE(sm.getDefaultState() == sm.getState(0));
      }

      THEN("can be started"){
        REQUIRE(sm.start() == true);
        AND_THEN("is running"){
          REQUIRE(sm.isRunning() == true);
          AND_THEN("can be stopped"){
            REQUIRE(sm.stop() == true);
          }
        }
        AND_THEN("shall reslove messages even if state name wasnt set")
        {
          REQUIRE(sm.recieve(m) == true);
        }
      }
      THEN("StateMachines state can be renamed")
      {
        const Text renamedState = "Renamed!";
        sm.getState(0).setName(renamedState);
        REQUIRE(sm.getState(0).getName() == renamedState);
        REQUIRE(sm.recieve(m) == true);
      }
      AND_WHEN("added another state"){
        auto default_constructed_state2 = State();
        sm.addState(default_constructed_state2);

        THEN("size should return 2"){
          REQUIRE(sm.size() == 2);
        }
        THEN("cannot be started, no default state can be selected"){
          REQUIRE(sm.start() == false);
          REQUIRE(sm.isRunning() == false);
        }

      }
    }
  }
}
