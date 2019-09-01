open ReactNative;
// open ReactNavigation;

[@react.component]
let make = () => {
  <>
    <View
      style=Style.(
        style(~flex=1., ~justifyContent=`center, ~alignItems=`center, ())
      )>
      <Text> {"Loading"->React.string} </Text>
    </View>
  </>;
};
