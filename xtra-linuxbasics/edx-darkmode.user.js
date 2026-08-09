// ==UserScript==
// @name         edX DarkMode
// @namespace    https://github.com/stinkerfish8/CS50X-2026/tree/main/xtra-linuxbasics
// @version      1.0.2
// @description  Forces dark mode and high-contrast text on edX while preserving quiz iframe readability
// @author       Stinker_Fish (assisted by Gemini AI)
// @icon         https://favicon.im/edx.org?larger=true
// @match        https://*.edx.org/*
// @match        https://learning.edx.org/*
// @match        https://*.algorea.org/*
// @grant        GM_addStyle
// @run-at       document-start
// ==/UserScript==

(function() {
    'use strict';
    const css = `
        /* 1. Override CSS variables of the Paragon framework (edX) */
        :root {
            --pgn-color-text-primary: #ffffff !important;
            --pgn-color-text-secondary: #e0e0e0 !important;
            --pgn-color-text-muted: #cccccc !important;
            --pgn-color-text-dark-700: #ffffff !important;
        }

        /* 2. General dark layout background */
        html, body, main, article, section, header, nav, footer {
            background-color: #121212 !important;
            color: #ffffff !important;
        }

        /* 3. Containers and cards */
        .raised-card, [class*="raised-card"], .card, [class*="card"] {
            background-color: #1a1a1a !important;
            border: 1px solid #333333 !important;
        }

        /* 4. Pure white text and reset opacity on standard layout elements (excluding play buttons/icons) */
        section *:not(.btn-play):not([class*="fa-"]), .raised-card *, div:not(.video-wrapper):not(.tc-wrapper), p, span:not(.btn-play):not([class*="fa-"]), h1, h2, h3, h4, h5, h6, li, td, th, label, small {
            background-color: transparent !important;
            color: #ffffff !important;
            opacity: 1 !important;
        }

        /* 5. Override edX muted and secondary classes to white/light gray */
        .text-dark-700, [class*="text-dark-"], [class*="text-muted"], [class*="muted"], [class*="secondary"], small {
            color: #e6e6e6 !important;
            opacity: 1 !important;
        }

        /* 6. SVG graphics and icons */
        svg, svg * {
            background-color: transparent !important;
        }

        /* 7. Complete exclusion of quiz iframes */
        iframe, iframe * {
            background-color: unset !important;
            color: unset !important;
            filter: none !important;
        }

        /* 8. High-contrast light blue links */
        a, a * {
            color: #64b5f6 !important;
        }

        /* 9. High-contrast blue text for navigation buttons (Previous / Next) */
        button:not(.btn-play), button:not(.btn-play) *, .btn:not(.btn-play), .btn:not(.btn-play) *, [role="button"], [role="button"] * {
            color: #0075b4 !important;
        }

        /* 10. Fix video player play button background and icon color */
        .video-wrapper, .tc-wrapper {
            background-color: #121212 !important;
        }
        .btn-play, [class*="fa-youtube-play"] {
            background-color: rgba(0, 0, 0, 0.7) !important;
            color: #64b5f6 !important;
        }
    `;

    if (typeof GM_addStyle !== 'undefined') {
        GM_addStyle(css);
    } else {
        const style = document.createElement('style');
        style.textContent = css;
        (document.head || document.documentElement).appendChild(style);
    }
})();
