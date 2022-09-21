// Older C++
enum class ConnectionState { DISCONNECTED,
                             CONNECTING,
                             CONNECTED,
                             CONNECTION_INTERRUPTED };

// Connection class
struct Connection {
    std::string server_address;
    ConnectionState connection_state;
    ConnectionId id;
    TimePoint connected_time;                      // Re-used as interrupted_time
    Milliseconds last_ping_time;
};

// C++17
struct Connection {
    std::string server_address;
    struct Disconnected {
        // Member functions for Disconnected state...
    };
    struct Connecting {
        // Member functions for Connecting state...
    };

    struct Connected {
        ConnectionId id;
        TimePoint connected_time;
        std::optional<Milliseconds> last_ping_time;
        // Member functions for Connected state...
    };

    struct ConnectionInterrupted {
        TimePoint interrupted_time;
        // Member functions for ConnectionInterrupted state...
    };

    std::variant<Disconnected, Connecting, Connected, ConnectionInterrupted> connection_state;
    // Member functions to manage the variant...
};
