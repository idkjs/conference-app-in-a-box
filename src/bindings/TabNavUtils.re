/** The reason-react-navigation bindings don't have initialRouteName and defaultNavigationOptions so I created StackUtils.re which copies over all of ReactNavigation.StackNavigator and overides the definition of config so that it has just the properties from react-navigation that I need to reproduce the example. It looks like this: */
include ReactNavigation.TabNavigator;
[@bs.obj]
external config:
  (
    ~defaultNavigationOptions: Js.t('a)=?,
    ~tabBarOptions:tabBarOptions=?,
    unit
  ) =>
  config =
  "";