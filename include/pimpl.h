#ifndef H_GAME_PIMLP
#define H_GAME_PIMLP

#include <memory>

#define PIMPL_PRIVATE_DATA private: \
    struct Private; \
    std::unique_ptr<Private> d;

#endif
