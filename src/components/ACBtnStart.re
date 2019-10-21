module Styles = {
  open Css;

  let container =
    style([
      unsafe("all", "unset"),
      unsafe(
        "boxShadow",
        "0 1px 2px 0 rgba(60,64,67,0.302), 0 1px 3px 1px rgba(60,64,67,0.149)",
      ),
      display(inlineFlex),
      alignItems(center),
      color(hex("3c4043")),
      paddingRight(px(24)),
      borderRadius(px(24)),
      fontWeight(bolder),
      fontSize(rem(0.875)),
      backgroundColor(hex("fff")),
      unsafe("letterSpacing", ".25px"),
      before([
        unsafe("content", ""),
        display(block),
        backgroundImage(
          url(
            "https://www.gstatic.com/images/icons/material/colored_icons/1x/create_32dp.png",
          ),
        ),
        unsafe("backgroundPosition", "center"),
        unsafe("backgroundSize", "32px"),
        backgroundRepeat(noRepeat),
        height(px(48)),
        minWidth(px(56)),
      ]),
    ]);
};

[@react.component]
let make = (~label="Compose") =>
  <button className=Styles.container> {React.string(label)} </button>;