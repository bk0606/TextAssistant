#ifndef TEXTASSISTANT_NGRAMCONTROLLERTEST_H
#define TEXTASSISTANT_NGRAMCONTROLLERTEST_H

#include <gtest/gtest.h>
#include "../NGramController.h"

namespace text_assistant {

    TEST (NGramsTest, Equality) {
        ConnectionSettings settings;
        settings.server = "localhost";
        settings.user = "root";
        settings.password = "defenderkella";
        settings.database = "text_assistant1";

        NGramController controller(10, settings);
        ASSERT_TRUE (controller.n == 10);
    }

}

#endif //TEXTASSISTANT_NGRAMCONTROLLERTEST_H
