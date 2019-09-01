open ReactNative;
open ReactNavigation;

let headerIcon = (~style as additionalStyle=Style.style(), source) =>
  <Image
    style=Style.(
      array([|
        style(~width=24.->dp, ~margin=11.->dp, ~height=24.->dp, ()),
        additionalStyle,
      |])
    )
    source
  />;

let tabBarIcon = (~name) =>
  NavigationOptions.TabBarIcon.render(props =>
    <FontAwesome
      name
      size=20
      color={props##focused ? Theme.Colors.highlight : "#fafafa"}
    />
  );

let rec getActiveRoute = route =>
  switch (route##routes) {
  | Some(routes) =>
    let routeCount = routes->Array.length;
    if (routeCount == 0 || route##index >= routeCount) {
      route;
    } else {
      getActiveRoute(routes->Belt.Array.getUnsafe(route##index));
    };
  | None => route
  };