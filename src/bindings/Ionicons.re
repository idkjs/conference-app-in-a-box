[@bs.module "react-native-vector-icons/Ionicons"] [@react.component]
external make:
  (
    // ~children: React.element=?,
    ~name: string=?,
    ~size: int=?,
    ~color: string=?,
    ~style: ReactNative.Style.t=?
  ) =>
  React.element =
  "Icon";