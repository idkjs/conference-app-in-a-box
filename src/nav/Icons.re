open ReactNative;

let filter =
  Image.Source.fromRequired(Packager.require("./Icons/filter.png"));

let settings =
  Image.Source.fromRequired(Packager.require("./Icons/settings.png"));

let home = Image.Source.fromRequired(Packager.require("./Icons/home.png"));

let message =
  Image.Source.fromRequired(Packager.require("./Icons/message.png"));

let notification =
  Image.Source.fromRequired(Packager.require("./Icons/notification.png"));

let search =
  Image.Source.fromRequired(Packager.require("./Icons/search.png"));

let compose =
  Image.Source.fromRequired(Packager.require("./Icons/compose.png"));

let avatar =
  Image.(
    Source.fromUriSource(
      uriSource(~uri="https://github.com/reasonml-community.png", ()),
    )
  );

module Ionicons = {
  [@bs.module "@expo/vector-icons"] [@react.component]
  external make:
    (~name: string, ~color: string=?, ~size: int=?) => React.element =
    "Ionicons";
};

module FontAwesome5 = {
  [@bs.module "@expo/vector-icons"] [@react.component]
  external make:
    (~name: string, ~color: string=?, ~size: int=?) => React.element =
    "FontAwesome5";
};

module IconShell = {
  [@react.component]
  let make = (~name, ~size=20) => {
    // let color =
    //   selected ? Styles.theme.palette.primary : Styles.theme.palette.grey;
    let tintColor = Theme.Colors.highlight;
    <View> <FontAwesome5 name size color=tintColor /> </View>;
  };
};
