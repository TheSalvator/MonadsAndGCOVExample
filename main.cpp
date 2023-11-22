#include <gtest/gtest.h>

#include <optional>

#if __cpp_lib_optional < 202110
#error "No monadic optional"
#endif

namespace {

struct image {};

std::optional<image> crop_to_cat(image img) {
    //
    return std::optional{img};
}

std::optional<image> add_bow_tie(image img) {
    //
    return std::optional{img};
}

std::optional<image> make_eyes_sparkle(image img) {
    //
    return std::nullopt;
}

image make_smaller(image img) {
    //
    return img;
}

image add_rainbow(image img) {
    //
    return img;
}

TEST(Monadic, Optional) {
    auto img = image{};

    // clang-format off
    crop_to_cat(img)
        .and_then(add_bow_tie)
        .and_then(make_eyes_sparkle)
        .transform(make_smaller)
        .transform(add_rainbow);
    // clang-format on
}

}  // namespace

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
