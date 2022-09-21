// Older C++
enum class AggressionState { IDLE, CHASING, FIGHTING };

class MonsterAggression {
    AggressionState aggro_state;
    float chase_radius;                // Start chasing if another player is within this distance
    Timer chase_time;                  // Start fighting after chasing for this length of time
    Player target;                     // The player we are chasing/fighting
    // Member functions...
};

// C++17
// We refactor the class into structs
// Each struct contains the data needed for each state
class MonsterAggression {
    struct Idle {                      // IDLE state
        float chase_radius;
        // Member functions for Idle state...
    };

    struct Chasing {                   // CHASING state
        Player target;
        Timer chase_time;
        // Member functions for Chasing state...
    };

    struct Fighting {                  // FIGHTING state
        Player target;
        // Member functions for Fighting state...
    };

    std::variant<Idle, Chasing, Fighting> aggro_state;    // std::variant with these alternatives
    // Member functions to manage the variant...
};