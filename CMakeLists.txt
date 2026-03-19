cmake_minimum_required(VERSION 3.22)
project(Gain VERSION 0.0.1)

# 1. Include FetchContent
include(FetchContent)

set(FETCHCONTENT_QUIET FALSE)

# 2. Declare JUCE (Cloud pull)
FetchContent_Declare(
    juce
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG        master 
)
FetchContent_MakeAvailable(juce)

# 3. Create the Plugin (Combined settings into ONE call)
juce_add_plugin(Gain
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT TRUE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS TRUE
    COPY_PLUGIN_AFTER_BUILD FALSE      
    FORMATS VST3 Standalone
    JUCE_VST3_CAN_REPLACE_VST2 FALSE            
)

# 4. Add Source Files
target_sources(Gain PRIVATE
    src/GainProcessor.cpp
    src/GainProcessor.h
    src/GainEditor.cpp
    src/GainEditor.h
)

# 5. Link JUCE Modules
target_link_libraries(Gain PRIVATE
    juce::juce_core
    juce::juce_audio_processors
    juce::juce_audio_utils
    juce::juce_audio_devices
)