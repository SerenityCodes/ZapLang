// This example demonstrates core language features: systems, components, structs, functions, aot block, and jobs.

// Define a component with entity data
component Health {
    value: u8;
}

readonly component Name {
    ascii_name: u8[];
}

// Define a struct for game settings
struct GameSettings {
    max_players: u16;
    gravity: f32;
}

// System to update health each frame
@system(Update)
func update_health(entity: u32, health: ref Health) {
    if (health.value > 0) {
        health.value = health.value - 1;
    }
}

// Run once before the main loop starts
@system(Init)
func init_system() {
    log("Initializing game systems...");
}

// Compile-time constant using aot block
func get_spawn_points() -> u32 {
    let points: u32 = aot {
        let result: u32 = 0;
        for (let i: u32 = 0; i < 10; i = i + 1) {
            result = result + 3;
        }
        yield result;
    };
    return points;
}

// Named function to be passed as a job
func load_assets() -> void {
    log("Running background loading task...");
}

// Main entry point
func main() -> void {
    engine.initialize();

    let settings: GameSettings = {
        max_players: 32,
        gravity: 9.81
    };

    log("Max players: ", settings.max_players);
    log("Spawn points: ", get_spawn_points());

    let job_id: u32 = job.spawn(load_assets);

    defer log("Game shutting down...");
}
