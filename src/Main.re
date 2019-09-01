// open ReactNative;
open ReactNative;
open ReactNavigation;

module TabNavigator = {
  let tabBarStyle = Style.(style(~backgroundColor=Theme.Colors.primary, ()));
  let tabBarOptions: TabNavigator.tabBarOptions =
    TabNavigator.tabBarOptions(
      ~activeTintColor=Theme.Colors.highlight,
      ~style=tabBarStyle,
      ~inactiveTintColor="#fafafa",
      (),
    );

  let routes = {
    "Schedule": {
      screen: Schedule.make,
    },
    "Profile": {
      screen: Profile.make,
    },
    "Map": {
      screen: Map.make,
    },
  };
let config =
  TabNavigator.config(~tabBarOptions, ());
  let navigator = TabNavigator.Bottom.(makeWithConfig(routes, config));

navigator->NavigationOptions.setDynamicNavigationOptions(params => {

    let routeName =
      params##navigation->Navigation.state->Helpers.getActiveRoute##routeName;
Js.log2("routeName", routeName);

let tabBarIcon = ()=>switch routeName {
        | "Schedule" => Helpers.tabBarIcon(~name=`calendar)
        | "Map" => Helpers.tabBarIcon(~name=`map)
        | _ => Helpers.tabBarIcon(~name=`user)
        };
Js.log2("tabBarIcon", tabBarIcon);
    NavigationOptions.t(~tabBarIcon=tabBarIcon(), ());
});
};

module TabNavWithPropsContainer =
  AppContainer.Make({
    type screenProps = {. "someProp": int};
    let navigator = TabNavigator.navigator;
  });

module TabNavWithProps = {
  [@react.component]
  let make = () => {
    let (token, setToken) = React.useState(() => None);
    React.useEffect(() => {
      setToken(_ => Some(Session.getToken()));
      None;
    });
    let screenProps = {"someProp": 42};
    switch (token) {
    | Some(token) =>
      <ReasonApollo.Provider client={AppSyncClient.client(token)}>
        <TabNavWithPropsContainer screenProps />
      </ReasonApollo.Provider>
    | None => <LoadingScreen />
    };
  };
};
module AppComponent = {
  open WithAuthenticator;
  let makeProps = TabNavWithProps.makeProps;
  let make =
    withAuthenticator(TabNavWithProps.make, ~theme=AmplifyTheme.theme, ());
};

[@react.component]
let make = () => {
  let (signedIn, setSignedIn) = React.useState(() => false);

  /* this useEffect ignores passed in props.
     Enter any thing you want to enter in componentDidMount. */
  React.useEffect1(
    () => {
      Auth.getCurrentAuthUser()
      |> Js.Promise.then_(result => {
           //  Js.log2("Auth.getCurrentAuthUser", result);
           switch (result) {
           | Belt.Result.Ok(_user) =>
             //  Js.log2("Auth.getCurrentAuthUser:result", user);
             setSignedIn(_ => true)
           | Belt.Result.Error(err) => Js.log2("user not signed in", err)
           };
           Js.Promise.resolve(result);
         })
      |> ignore;
      None;
    },
    [||] // This is the key as this effect will be independent of any change in props.
  );
  // This will allow the change of the state/props only if certain props are passed or changed to.
  React.useEffect1(
    () => {
      signedIn
        ? Js.log("User is signed in.") : Js.log("User is NOT signed in.");
      None;
    },
    [|signedIn|] // Here we are listing dependency on which component will be re-rendered.
  );
  React.useEffect(() => {
    Hub.listen(`change(state => Js.log2("Hub.listen", state)));
    Some(() => Hub.remove(`change(state => Js.log2("Hub.remove", state))));
  });

  let renderLogo = !signedIn ? <Logo /> : React.null;
  <View style=Style.(style(~flex=1., ()))>
    renderLogo
    <AppComponent />
  </View>;
};