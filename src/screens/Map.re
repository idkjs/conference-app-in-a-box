open ReactNative;
open ReactNavigation;
include Theme;
open ReactNativeMaps;

let styles =
  StyleSheet.create(
    Style.{
      "mapStyle":
        style(
          ~width=(dimensions##width -. 40.)->dp,
          ~height=400.->dp,
          ~borderRadius=5.,
          (),
        ),
      "addressContainer": style(~paddingVertical=20.->dp, ()),
      "address":
        style(
          ~color=Colors.primaryText,
          ~fontSize=18.,
          ~marginBottom=4.->dp,
          ~fontFamily=Typography.primary,
          (),
        ),
      "addressHeading":
        style(
          ~fontSize=18.,
          ~fontWeight=`_500,
          ~marginBottom=5.->dp,
          ~color=Colors.highlight,
          (),
        ),
      "rocketView": style(~fontSize=24., ()),
      "container": style(~flex=1., ~backgroundColor=Colors.primary2, ()),
      "mapContainer": style(~flex=1., ()),
      "mapView": style(~padding=20.->dp, ()),
    },
  );
let rocketIcon = {js|🚀|js};
[@react.component]
let make = () => {
  <View style=styles##container>
    <BaseHeader />
    <View style=styles##mapContainer>
      <ScrollView>
        <View style=styles##mapView>
          <MapView
            style=styles##mapStyle
            region={
              "latitude": 37.78825,
              "longitude": (-122.4324),
              "latitudeDelta": 0.0922,
              "longitudeDelta": 0.0421,
            }
            initialRegion={
              "latitude": 37.78825,
              "longitude": (-122.4324),
              "latitudeDelta": 0.0922,
              "longitudeDelta": 0.0421,
            }>
            <Marker
              coordinate={"latitude": 37.78825, "longitude": (-122.4324)}>
              <View>
                <Text style=styles##rocketView>
                  {rocketIcon |> React.string}
                </Text>
              </View>
            </Marker>
          </MapView>
          <TouchableHighlight
            onPress={_e =>
              Js.Promise.(
                Linking.openURL("https://goo.gl/maps/DNrmyCTQPDC5RkHc9")
                |> then_(_ =>
                     Js.log(
                       "opened " ++ "https://goo.gl/maps/DNrmyCTQPDC5RkHc9",
                     )
                     |> resolve
                   )
                |> ignore
              )
            }
            underlayColor="transparent">
            <View style=styles##addressContainer>
              <Text
                style=Style.(list([styles##address, styles##addressHeading]))>
                {"AWS Loft" |> React.string}
              </Text>
              <Text style=styles##address>
                {"525 Market St #2" |> React.string}
              </Text>
              <Text style=styles##address>
                {"San Francisco, CA 94105" |> React.string}
              </Text>
            </View>
          </TouchableHighlight>
        </View>
      </ScrollView>
    </View>
  </View>;
};
make->NavigationOptions.setNavigationOptions(NavigationOptions.t(~title="Map",
~tabBarIcon=Helpers.tabBarIcon(~name=`map),
// ~tabBarIcon=Helpers.tabBarIcon(Icons.home),
 ()));
