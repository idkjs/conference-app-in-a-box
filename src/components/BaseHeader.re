open ReactNative;

let styles =
  StyleSheet.create(
    Style.{
      "container":
        style(
          ~backgroundColor="rgba(18, 25, 50, 1)",
          ~height=88.->dp,
          ~alignItems=`center,
          (),
        ),
      "logo":
        style(
          ~position=`absolute,
          ~height=35.->dp,
          ~left=10.->dp,
          ~bottom=7.->dp,
          ~width=120.->dp,
          (),
        ),
    },
  );
[@react.component]
let make = () =>
  <View style=styles##container>
    <Image source=Theme.logo resizeMode=`contain style=styles##logo />
  </View>;
// [@genType]
// let default = make
