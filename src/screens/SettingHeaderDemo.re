/**
 * Demo `Setting Header Title` React Navigation Module
 * https://reactnavigation.org/
 *
 * Converted to reasonml from https://reactnavigation.org/docs/en/headers.html#setting-the-header-title
 *
 */
open ReactNative;

open ReactNavigation;
let styles =
  Style.(
    StyleSheet.create({
      "screen":
        style(~flex=1., ~justifyContent=`center, ~alignItems=`center, ()),
    })
  );
module HomeScreen = {
  [@react.component]
  let make = (~navigation: Navigation.t) => {
    /** trying this to see if we can work towards json serializable values to use with deeplinking as mentioned here: https://reactnavigation.org/docs/en/params.html */

    let params = {
        "itemId": 86,
        "otherParam": "anything you want here",
      };
    // Js.log2("TEST", Js.Json.test(params, Object)); // true
          <View style=Style.(style(~flex=1., ~alignItems=`center, ~justifyContent=`center,()))>
        <Text>"Home Screen"->React.string</Text>

      <Button
        title="Go to Details"
        onPress={_ =>
          navigation->Navigation.navigateWithParams("Details", params)
          // {"itemId": 86, "otherParam": "anything you want here"},
        }
        /**  js version
        // onPress={() => {
        //     /* 1. Navigate to the Details route with params */
        //     this.props.navigation.navigate('Details', {
        //       itemId: 86,
        //       otherParam: 'anything you want here',
        //     });
        //   }}*/
      />
    </View>;
  };
  make->NavigationOptions.setNavigationOptions(NavigationOptions.t(~title="Home", ()));
};
module Categories = {
  [@react.component]
  let make = (~navigation) =>
    <View style=styles##screen>
      <Text> "Categories"->React.string </Text>
      <Button
        title="Go to Meals!"
        onPress={_ => navigation->Navigation.navigate("CategoryMeals")}
      />
    </View>;

  make->NavigationOptions.setNavigationOptions(
    NavigationOptions.t(~title="Categories", ()),
  );
};
module DetailsScreen = {
  [@react.component]
  let make = (~navigation: Navigation.t) => {
    /** in reason-react-native you have to use `navigateWithParams` to get be able to use the default value behaviour shown in the example here: https://reactnavigation.org/docs/en/params.html */
    let itemId =
      navigation->Navigation.getParamWithDefault("itemId", "NO-ID");

    let otherParam =
      navigation->Navigation.getParamWithDefault(
        "otherParam",
        "some default value",
      );

    <View
      style=Style.(
        style(~flex=1., ~alignItems=`center, ~justifyContent=`center, ())
      )>
      <Text> {"Details Screen" |> React.string} </Text>
      <Text> {"itemId: " ++ itemId |> React.string} </Text>
      <Text> {"otherParam: " ++ otherParam |> React.string} </Text>
      <Button
        title="Go to Details... again"
        onPress={_ =>
          navigation->Navigation.navigateWithParams(
            "Details",
            {
              "itemId": [%bs.raw {| String(Math.floor(Math.random() * 100)) |}],
            },
          )
        }
      />
      <Button
        title="Go to Home"
        onPress={_ => navigation->Navigation.navigate("Home")}
      />
      <Button title="Go back" onPress={_ => navigation->Navigation.goBack} />
    </View>;
  };
  make->NavigationOptions.setDynamicNavigationOptions(params => {
    let title = params##navigation->Navigation.getParamWithDefault("otherParam", "A Nested Details Screen");
    (NavigationOptions.t(~title, ()));
  });
};
module SettingsScreen = {
  [@react.component]
  let make = () => {
    <View style=styles##screen>
      <Text> "Settings Screen"->React.string </Text>
    </View>;
  };
};
module ProfileScreen = {
  [@react.component]
  let make = () => {
     <View style=styles##screen>
      <Text> "Profile Screen"->React.string </Text>
    </View>;
  };
};

module HomeStack = {
  let navigator =
    StackNavigator.(
      make({"Home": HomeScreen.make, "Details": DetailsScreen.make})
    );
};
module SettingsStack = {
  let navigator =
    StackNavigator.(
      make({
        "Profile": ProfileScreen.make,
        "SettingsScreen": SettingsScreen.make,
      })
    );
};
let navigator =
      ReactNavigation.TabNavigator.Bottom.make({
        "Home": HomeStack.navigator,
        "Settings": SettingsStack.navigator,
      });