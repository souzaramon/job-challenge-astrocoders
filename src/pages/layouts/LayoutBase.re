open Types;

module Styles = {
  open Css;

  let container = (~acOverrides) =>
    merge([
      style([
        unsafe("backgroundPosition", "center"),
        width(pct(100.0)),
        height(pct(100.0)),
        display(flexBox),
        flexDirection(column),
        overflowX(hidden),
        backgroundRepeat(noRepeat),
        backgroundSize(cover),
      ]),
      style(acOverrides),
    ]);

  let content =
    style([width(pct(100.0)), height(pct(100.0)), display(flexBox)]);

  let slot =
    style([width(pct(100.0)), height(pct(100.0)), display(flexBox)]);
};

[@react.component]
let make = (~children, ~theme) => {
  let (sidebarIsDense, setSidebarIsDense) = React.useState(() => false);

  <div className={Styles.container(~acOverrides=[theme.background])}>
    <ACHeader
      dark={theme.dark}
      cbClickToggleBtn={_ => setSidebarIsDense(_ => !sidebarIsDense)}
    />
    <div className=Styles.content>
      <ACSidebar dark={theme.dark} dense=sidebarIsDense />
      <div className=Styles.slot> children </div>
    </div>
  </div>;
};