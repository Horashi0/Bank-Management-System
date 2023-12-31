#include <stdio.h>
#include <string.h>
#include <time.h>

int delay(long milliseconds)
{
    struct timespec req = {
        (int)(milliseconds / 1000),     /* secs (Must be Non-Negative) */ 
        (milliseconds % 1000) * 1000000 /* nano (Must be in range of 0 to 999999999) */
    };

    return nanosleep(&req, NULL);
}


void startup(void)
{
    const char *const lines[] = {
        "      :::    :::          ::::::::          :::::::::              :::           ::::::::          :::    :::          :::::::::::          :::::::: ",
        "     :+:    :+:         :+:    :+:         :+:    :+:           :+: :+:        :+:    :+:         :+:    :+:              :+:             :+:    :+: ",
        "    +:+    +:+         +:+    +:+         +:+    +:+          +:+   +:+       +:+                +:+    +:+              +:+             +:+    +:+  ",
        "   +#++:++#++         +#+    +:+         +#++:++#:          +#++:++#++:      +#++:++#++         +#++:++#++              +#+             +#+    +:+   ",
        "  +#+    +#+         +#+    +#+         +#+    +#+         +#+     +#+             +#+         +#+    +#+              +#+             +#+    +#+    ",
        " #+#    #+#         #+#    #+#         #+#    #+#         #+#     #+#      #+#    #+#         #+#    #+#              #+#             #+#    #+#     ",
        "###    ###          ########          ###    ###         ###     ###       ########          ###    ###          ###########          ########       ",
        "      :::::::::              :::           ::::    :::          :::    :::          :::::::::::          ::::    :::          ::::::::               ",
        "     :+:    :+:           :+: :+:         :+:+:   :+:          :+:   :+:               :+:              :+:+:   :+:         :+:    :+:               ",
        "    +:+    +:+          +:+   +:+        :+:+:+  +:+          +:+  +:+                +:+              :+:+:+  +:+         +:+                       ",
        "   +#++:++#+          +#++:++#++:       +#+ +:+ +#+          +#++:++                 +#+              +#+ +:+ +#+         :#:                        ",
        "  +#+    +#+         +#+     +#+       +#+  +#+#+#          +#+  +#+                +#+              +#+  +#+#+#         +#+   +#+#                  ",
        " #+#    #+#         #+#     #+#       #+#   #+#+#          #+#   #+#               #+#              #+#   #+#+#         #+#    #+#                   ",
        "#########          ###     ###       ###    ####          ###    ###          ###########          ###    ####          ########                     "
    };
    int i, max;
    for (i = 0, max = (sizeof(lines) / sizeof(*lines)); i < max; ++i)
    {
        puts(lines[i]);
        delay(100);
    }
    
}
int main()
{
    startup();
}