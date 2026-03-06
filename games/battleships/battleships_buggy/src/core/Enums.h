#pragma once
#include <cstdint>

namespace bs {

    enum class Orientation : std::uint8_t
    {
        Horizontal,
        Vertical
    };

    enum class ShotResult : std::uint8_t
    {
        Miss,
        Hit,
        Sunk,
        AlreadyTried, // intended by spec, buggy code may not return it correctly
        Invalid
    };

    enum class PlaceResult : std::uint8_t
    {
        Ok,
        OutOfBounds,
        Overlap,
        Invalid
    };
    inline const char* ToString(PlaceResult r)
    {
        switch (r)
        {
        case PlaceResult::Ok: return "Ok";
        case PlaceResult::OutOfBounds: return "OutOfBounds";
        case PlaceResult::Overlap: return "Overlap";
        case PlaceResult::Invalid: return "Invalid";
        default: return "Unknown";
        }
    }
    

} // namespace bs