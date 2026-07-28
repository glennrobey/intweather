interface LayoutProps {
  children: React.ReactNode;
}

function Layout({ children }: LayoutProps) {
  return (
    <div
      className="
        min-h-screen
        bg-gradient-to-br
        from-gray-900
        via-gray-700
        to-gray-500
        flex
        flex-col
        items-center
        justify-center
        p-6
      "
    >
      {children}
    </div>
  );
}

export default Layout;
