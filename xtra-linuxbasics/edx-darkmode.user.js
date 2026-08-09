// ==UserScript==
// @name         edX DarkMode
// @namespace    https://github.com/stinkerfish8/CS50X-2026/tree/main/xtra-linuxbasics
// @version      1.0.0
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
        /* Dark background and light text for the interface */
        html, body, header, nav, footer, main, article, section, div, p, span, h1, h2, h3, h4, li {
            background-color: #121212 !important;
            color: #e0e0e0 !important;
            border-color: #333333 !important;
        }

        /* Completely exclude iframe and its content from dark mode */
        iframe, iframe * {
            background-color: unset !important;
            color: unset !important;
            filter: none !important;
        }

        /* High contrast link color for the interface */
        a {
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
