#include <stdint.h>
#include <graphene/utilities/git_revision.hpp>

#define GRAPHENE_GIT_REVISION_SHA "015026f005123a507c572a0318565383c92e0820"
#define GRAPHENE_GIT_REVISION_UNIX_TIMESTAMP 1513118559
#define GRAPHENE_GIT_REVISION_DESCRIPTION "2.0.171212"

namespace graphene { namespace utilities {

const char* const git_revision_sha = GRAPHENE_GIT_REVISION_SHA;
const uint32_t git_revision_unix_timestamp = GRAPHENE_GIT_REVISION_UNIX_TIMESTAMP;
const char* const git_revision_description = GRAPHENE_GIT_REVISION_DESCRIPTION;

} } // end namespace graphene::utilities
