# Verify GCC installation
if ! command -v gcc &> /dev/null; then
    echo "Error: GCC is not installed or not in PATH. Please install GCC."
    echo "Current PATH: $PATH"
    exit 1
fi

# Verify CMake installation
if ! command -v cmake &> /dev/null; then
    echo "Error: CMake is not installed or not in PATH. Please install CMake."
    echo "Current PATH: $PATH"
    exit 1
fi

# Verify GDB installation
if ! command -v gdb &> /dev/null; then
    echo "Error: GDB is not installed or not in PATH. Please install GDB."
    echo "Current PATH: $PATH"
    exit 1
fi

# Print confirmation
echo "Environment is ready for C++ development."

exec "$@"
